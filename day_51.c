//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                      struct TreeNode* p, 
                                      struct TreeNode* q) {
    if (root == NULL) return NULL;

    // If both nodes are smaller, go left
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both nodes are greater, go right
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise, root is the LCA
    return root;
}

// Driver code to test
int main() {
    // Constructing BST manually
    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);

    struct TreeNode* p = root->left;       // Node 2
    struct TreeNode* q = root->right;      // Node 8

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is %d\n", p->val, q->val, lca->val);

    return 0;
}