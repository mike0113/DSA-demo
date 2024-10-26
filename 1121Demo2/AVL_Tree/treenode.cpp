#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>
#include <QPainter>
#include <QLabel>
#include <string>
using std::string;
TreeNode::TreeNode()
{

}


// A utility function to get the
// height of the tree
int TreeNode::toheight(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// A utility function to get maximum
// of two integers
int TreeNode::max(int a, int b)
{
    return (a > b)? a : b;
}

TreeNode* TreeNode::NEWnodeANDinputdata(int data)
{
    //TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *temp = new TreeNode;
    temp->key = data;
    temp->left = temp->right = NULL;
    temp->height = 1;   // new node is initially added at leaf
    return temp;
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
TreeNode* TreeNode::rightRotate(TreeNode *y)    // L-L rotation
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(toheight(y->left),toheight(y->right)) + 1;
    x->height = max(toheight(x->left),toheight(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
TreeNode *TreeNode::leftRotate(TreeNode *x)     //R-R rotation
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(toheight(x->left),toheight(x->right)) + 1;
    y->height = max(toheight(y->left),toheight(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int TreeNode::getBalance(TreeNode *N)
{
    if (N == NULL)
        return 0;
    return toheight(N->left) - toheight(N->right);
}



/* A utility function to insert a new node with given key in BST */
TreeNode* TreeNode::insert(TreeNode* node, int key)
{
    /* If the tree is empty or leaf, return a new node */
    if (node == NULL)
        return NEWnodeANDinputdata(key);

    /* Otherwise, recur down the tree */
    if (key <= node->key)       //leftsubtree
        node->left = insert(node->left, key);
    else if (key > node->key)   //rughtsubtree
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(toheight(node->left),toheight(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)   //first R-R ,then L-L
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) //first L-L ,then R-R
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;

}
TreeNode* TreeNode::minValueNode(TreeNode* node)
{
    TreeNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
TreeNode* TreeNode::deleteNode(TreeNode* node, int key)
{
    // base case
    if (node == NULL)
        return node;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < node->key)
        node->left = deleteNode(node->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > node->key)
        node->right = deleteNode(node->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (node->left == NULL)
        {
            TreeNode *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            TreeNode *temp = node->left;
            free(node);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->key = temp->key;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

