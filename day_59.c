//Construct a binary tree from given inorder and postorder traversal arrays.
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

// Find index of a value in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive helper to build tree
struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd,
                                 int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    // Root is the last element in postorder
    int rootVal = postorder[postEnd];
    struct TreeNode* root = newNode(rootVal);

    // Find root index in inorder
    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);

    int leftSize = rootIndex - inStart;

    // Build left subtree
    root->left = buildTreeHelper(inorder, inStart, rootIndex - 1,
                                 postorder, postStart, postStart + leftSize - 1);

    // Build right subtree
    root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd,
                                  postorder, postStart + leftSize, postEnd - 1);

    return root;
}

// Main function to build tree
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}

// Preorder traversal to verify tree
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Example input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
    int postorderSize = sizeof(postorder) / sizeof(postorder[0]);

    struct TreeNode* root = buildTree(inorder, inorderSize, postorder, postorderSize);

    printf("Preorder traversal of constructed tree:\n");
    preorder(root);
    printf("\n");

    return 0;
}