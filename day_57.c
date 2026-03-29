//Convert a binary tree into its mirror image by swapping left and right children at every node.
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
// Function to mirror the binary tree
void mirror(struct TreeNode* root) {
    if (root == NULL) return;
    // Swap left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}
// Helper function to print the tree in-order (for testing)
void inOrder(struct TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}
int main() {
    // Build example tree: [1,2,3]
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Original tree in-order: ");
    inOrder(root);
    printf("\n");

    mirror(root);

    printf("Mirrored tree in-order: ");
    inOrder(root);
    printf("\n");

    return 0;
}
