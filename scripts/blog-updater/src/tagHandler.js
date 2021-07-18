import { select, selectAll } from 'unist-util-select';
import { visit } from 'unist-util-visit';
import _ from 'lodash';

const TagsNodeName = 'tags';

// remove hash from tag item if first character is '#'
const removeHashFromTagItem = (tagItem) => {
  if (tagItem.startsWith('#')) {
    return tagItem.slice(1);
  }
  return tagItem;
};

const getTextValueOfListItem = (listItem) => {
  const text = _.get(listItem, 'children[0].children[0].value');
  return text;
};

const detectTagsNodePlugin = () => (tree) => {
  // console.warn('HANDLE CALL')
  const lastHeadingNode = select('root > heading:last-of-type', tree);
  const lastHeadingNodeValue = _.get(lastHeadingNode, 'children[0].value');

  if(lastHeadingNodeValue != TagsNodeName) {
    console.error('NO TAGS. SKIPPING');
    return;
  }

  const tagsHeadingNode = lastHeadingNode;

  markTocTagItem(tree);

  if(!tree.data){
    tree.data = {
      removeTarget: [],
    }
  }

  // console.info('DATA', tree.data);

  // tagsNode including heading node for removeTarget
  let tagsNodes = [tagsHeadingNode];
  // string list of tags
  let tagsItem = [];
  visit(tree, ['heading', 'list', 'paragraph'], (node, index, parent) => {
    if(node == tagsHeadingNode) {
      // console.info('idex',index, 'parent',parent);
      const targetTagsNode = _.get(parent, `children[${index+1}]`);
      if(!targetTagsNode) {
        console.error('NO TAGS NODE FOUND');
        return;
      }
      const targetNode = targetTagsNode;
      const isList = targetNode.type === 'list';
      const isParagraph = targetNode.type === 'paragraph';
      const isTagItemNode = (isList || isParagraph);
      if(isTagItemNode) {
        // console.info('FIND', targetNode);
        tagsNodes.push(targetNode);
      }
      if(isParagraph) {
        // console.info('PARAGRAPH targetNode', targetNode, index);
        // get single text value of paragraph node
        const paragraphNodeValue = _.get(targetNode, 'children[0].value');
        // remove hashes if exist
        const value = paragraphNodeValue;
        tagsItem = value.split(/[\s,]+/).map(item => removeHashFromTagItem(item));
      }
      else if(isList) {
        // check if this list is multi line or single listitem by checking listitem's length
        const listItemNodes = selectAll('listItem', targetNode);
        const isMultiLineList = listItemNodes.length > 1;
        if(isMultiLineList) {
          tagsItem = listItemNodes
            .map(listItemNode => getTextValueOfListItem(listItemNode))
            .map(item=>removeHashFromTagItem(item));
        } else {
          const value = getTextValueOfListItem(listItemNodes[0]);
          tagsItem = value.split(/[\s,]+/).map(item => removeHashFromTagItem(item));
        }
        
      }

    }
  })

  // const tagsItem = extractTagsItemFromTagsNode(tagsNodes);
  tree.data = {
    ...tree.data,
    tagsNodes,
    tags: tagsItem,
    category: tagsItem[0]
  }

  // console.info(tree.data);
  // concat all tags nodes to remove target
  tree.data.removeTarget = tree.data.tagsNodes.concat(tree.data.removeTarget);

  return tree;
};

// toc handler
const markTocTagItem = (tree) => {
  const tocListLastTagItem = select('root > heading:first-of-type ~ list:first-of-type > listItem:last-of-type', tree);
  tree.data.removeTarget.push(tocListLastTagItem);
  return tree;
};

export default {
  handle: detectTagsNodePlugin,
}