#ifndef TREENODE_H
#define TREENODE_H


class TreeNode
{
public:
    TreeNode();
    TreeNode* NEWnodeANDinputdata(int data);
    TreeNode* insert(TreeNode* node, int key);
    TreeNode* minValueNode(TreeNode* node);
    TreeNode* deleteNode(TreeNode* node, int key);

    int key;
    TreeNode *left, *right;
};

#endif // TREENODE_H
