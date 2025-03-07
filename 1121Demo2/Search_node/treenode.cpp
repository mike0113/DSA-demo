#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>
#include <QPainter>
#include <QLabel>
#include <string>
using std::string;

TreeNode::TreeNode()
{
    search="";
}


TreeNode* TreeNode::NEWnodeANDinputdata(int data)
{
    //TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *temp = new TreeNode;
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
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

string TreeNode::SearchNode(TreeNode* node, int key){


    if (node == NULL){
        return  search;

    }

    if (key <= node->key){       //leftsubtree
        search += std::to_string(node->key)+' ';
        SearchNode(node->left, key);
    }
    else if (key > node->key){   //rughtsubtree
        search += std::to_string(node->key)+' ';
        SearchNode(node->right, key);
    }
    else{    //find it
        search += std::to_string(node->key) +' ';

    }

    return search;
}
