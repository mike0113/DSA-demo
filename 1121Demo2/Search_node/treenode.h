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
    string SearchNode(TreeNode* node, int key);

    int key;
    string search;
    TreeNode *left, *right;
};

#endif // TREENODE_H
