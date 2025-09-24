#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using std::string;

class TreeNode
{
public:
    TreeNode();
    TreeNode* NEWnodeANDinputdata(int data);
    TreeNode* insert(TreeNode* node, int key);
    TreeNode* minValueNode(TreeNode* node);
    TreeNode* deleteNode(TreeNode* node, int key);
    TreeNode* rightRotate(TreeNode *y);
    TreeNode* leftRotate(TreeNode *x);
    int getBalance(TreeNode *N);
    int toheight(TreeNode* node);
    int max(int a, int b);

    int key;
    int height;
    TreeNode *left, *right;
};

#endif // TREENODE_H
