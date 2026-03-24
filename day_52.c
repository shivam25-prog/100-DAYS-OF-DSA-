//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to find LCA
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left != NULL && right != NULL) {
        return root;
    }
    
    return (left != NULL) ? left : right;
}

int main() {
    // Build the example tree:
    //        3
    //       / \
    //      5   1
    //     / \  / \
    //    6  2 0  8
    //      / \
    //     7   4
    
    struct TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct TreeNode* p = root->left;      // Node 5
    struct TreeNode* q = root->right;     // Node 1

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is %d\n", p->val, q->val, lca->val);

    return 0;
}