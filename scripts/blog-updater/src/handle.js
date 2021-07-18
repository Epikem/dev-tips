import fs, { read } from 'fs';
import unified from 'unified';
import parse from 'remark-parse';
import gfm from 'remark-gfm';
import stringify from 'remark-stringify';
import path from 'path';
import frontmatter from 'remark-frontmatter';
import { visit } from 'unist-util-visit';
import { select } from 'unist-util-select';
import { u } from 'unist-builder';
import _ from 'lodash';
import tagHandler from './tag-handler.js';

// WORKING DIRECTORY: ./scripts/blog-updater
const YEAR = '2021';
// const IN_DIR = './src/' + YEAR;
const IN_DIR = path.join(process.env.SOURCE_DIR) || './src/' + YEAR;
// const OUT_DIR = './src/test-out-dir';
const OUT_DIR = path.join(process.env.TARGET_DIR) || './src/test-out-dir';
console.log('source dir', IN_DIR);
console.log('target dir', OUT_DIR);

const writeDir = path.join(OUT_DIR, YEAR);

fs.rmSync(writeDir, {
  force: true,
  recursive: true
});

fs.mkdirSync(writeDir, {
  recursive: true,
});

fs.readdir(IN_DIR, (err, filenames) => {
  if(err) {
    throw err;
  }

  filenames.forEach(filename => {
    let filenameinfo = path.parse(filename);

    if(filenameinfo.ext != '.md') {
      console.info('skip file', filename);
      return;
    }

    const readFilePath = path.join(IN_DIR, filename);
    
    const file_info = {
      // NOTE: USING FILENAME AS DATE, 다른 로그 할때는 변경할것.
      date: filenameinfo.name.slice(0,10),
      private: filenameinfo.name.slice(-2) == '-p'
    };

    if(file_info.private){
      console.warn('private. skipping', filename);
      return;
    }

    const readFile = fs.readFileSync(readFilePath, {
      encoding: 'utf8'
    });

    // PROCESS
    const result = processFile(readFile, {
      ...file_info,
    });

    console.info('done', filename);
    // console.info('done', filename, 'result DATA: ', result);
    
    const writeFilePath = path.join(writeDir, file_info.date + '-' + result.data.title.replaceAll(/\s/g, '-') + '.md');

    fs.writeFileSync(writeFilePath, result.runData.toString({
      encoding: 'utf-8'
    }), {
      encoding: 'utf-8'
    });
  })
})

// define a unified js process that does:
// 1. parses markdown to tree
// 2. check if the tree has a heading with depth 1 and a frontmatter
// 3. if it has, do the following:
//  1. assign the heading value to content_info['title'] and remove the heading node
//  2. find a tag heading node and remove it
//  3. find a toc node from toc list and remove it
//  4. find a tags node from tag list, assing it to content_info['tags'] and remove it
// 4. if it does not have, do not process the tree

const getTextValueOfNode = (node) => _.get(node, 'children[0].value') || _.get(node, 'value');

const processFile = (file, options) => {
  let result = {};
  result.runData = getExtractor(options)
    .use(()=>(tree)=>{
      result.data = tree.data;
    })
    .processSync(file);

  return result;
}

const getExtractor = (option) => {
  return unified()
  .use(parse)
  .use(gfm)
  // 2. check if the tree has a heading with depth 1 and a frontmatter
  .use(() => (tree) => {
    // init tree data
    tree.data = {
      should_transform: true,
      removeTarget: [],
      tagsItem: [],
      title: option.title || '',
      date: option.date || '',
      private: option.private || false,
    }
    const firstHeading = select('root > heading:first-of-type', tree);
    // check if tree has a yaml or toml frontmatter
    const frontmatter = select('root > yaml', tree) || select('root > toml', tree);
    
    // check if first heading is depth 1
    if(firstHeading.depth != 1 || frontmatter) {
      console.warn('has frontmatter or not have title heading. skipping');
      tree.data.should_transfrom=false;
      return;
    } else {
      tree.data.should_transform=true;
    }
    tree.data.title = getTextValueOfNode(firstHeading);
    tree.data.removeTarget.push(firstHeading);
    
    // return tree
    return tree;
  })
  .use(() => (tree) => {
    // select last heading
    const lastHeading = select('root > heading:last-of-type', tree);
    // check if last heading is tags heading
    const hasTagsHeading = _.get(lastHeading, 'children[0].value') == 'tags';

    if(hasTagsHeading) {
      tree.data.removeTarget.push(lastHeading);
    }
    return tree;
  })
  // handle the tags node using tagHandler
  .use(tagHandler.handle)
  // remove remove targets from tree
  .use(() => (tree) => {
    // should transform
    if(tree.data.should_transform) {
      visit(tree, (node, index, parent) => {
        if(tree.data.removeTarget.includes(node)) {
          parent.children.splice(index, 1);
          return [visit.SKIP, index];
        }
      });
    }

    return tree;
  })
  .use(() => (tree) => {
    const data = tree.data;
    if(data.should_transform){
      const frontmatter = u('yaml', {
        value: [
          `date: "${data.date}"`,
          `title: "${data.title}"`,
          `categories: "${data.category}"`,
          `tags: ["${data.tags.join('", "')}"]`,
        ].join('\n'),
      })
      tree.children.unshift(frontmatter);
    }
  })
  // stringify tree
  .use(stringify, {
    bullet: '-',
    fence: '`',
    fences: true,
    incrementListMarker: false,
    rule: '-',
    ruleRepetition: 10,
    listItemIndent: 'mixed',
  })
  .use(frontmatter, ['yaml'])
};
