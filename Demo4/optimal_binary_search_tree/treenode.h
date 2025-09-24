#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
public:
    TreeNode();
    TreeNode* NEWnodeANDinputdata(char data);
    TreeNode* insert(TreeNode* node, int Dir, char data);
    TreeNode* minValueNode(TreeNode* node);
    TreeNode* deleteNode(TreeNode* node, int key);

    char key;
    TreeNode *left, *right;
};

#endif // TREENODE_H
