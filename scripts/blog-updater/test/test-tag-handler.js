import fs from 'fs';
import { expect } from "chai";
import tagHandler from '../src/tag-handler.js';
import unified from 'unified';
import parse from 'remark-parse';
import gfm from 'remark-gfm';

describe('Tag Handler', ()=>{
  it('should handle one line list item tag', () => {
    const parser = unified()
    .use(parse)
    .use(gfm)
    .use(tagHandler.handle);

    const oneLineListItemTag = fs.readFileSync('./test/fixture/one-line-list-item-tags.md', {
      encoding: 'utf8'
    });

    let tree = parser.parse(oneLineListItemTag);
    tree = parser.runSync(tree);

    // const originalTagLine = `#blog, #server, #cloud/aws, \#escaped-tag, \#tag_with_underbar`;
    // const answer = ['#blog, #server, #cloud/aws, \#escaped-tag, \#tag_with_underbar']
    const answer = [
      'blog',
      'server',
      'cloud/aws',
      'escaped-tag',
      'tag_with_underbar',
      'tag_with_omitted_hash'
    ];
    expect(tree.data.tags).to.deep.equal(answer);
  })

  it('should handle multi line list item tag', () => {
    const parser = unified()
    .use(parse)
    .use(gfm)
    .use(tagHandler.handle);

    const multiLineListItemTag = fs.readFileSync('./test/fixture/multi-line-list-item-tags.md', {
      encoding: 'utf8'
    });

    let tree = parser.parse(multiLineListItemTag);
    tree = parser.runSync(tree);

    // const originalTagLine = `#blog, #server, #cloud/aws, \#escaped-tag, \#tag_with_underbar`;
    // const answer = ['#blog, #server, #cloud/aws, \#escaped-tag, \#tag_with_underbar']
    const answer = [
      'blog',
      'server',
      'cloud/gcp',
      'docker',
      'dashed-tag',
      'tag_with_underbar',
    ];
    expect(tree.data.tags).to.deep.equal(answer);
  })

  it('should handle one line paragraph tags', () => {
    const parser = unified()
    .use(parse)
    .use(gfm)
    .use(tagHandler.handle);

    const oneLineParagraphTags = fs.readFileSync('./test/fixture/one-line-paragraph-tags.md', {
      encoding: 'utf8'
    });

    let tree = parser.parse(oneLineParagraphTags);
    tree = parser.runSync(tree);

    // answer: #blog, #client, #vuejs, #redux, \#escaped-tag, \#tag_with_underbar
    const answer = [
      'blog',
      'client',
      'vuejs',
      'redux',
      'escaped-tag',
      'tag_with_underbar',
    ];

    expect(tree.data.tags).to.deep.equal(answer);
  })

  
})

