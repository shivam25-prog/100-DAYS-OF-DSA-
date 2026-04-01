//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Check completeness using BFS
bool isComplete(struct TreeNode* root) {
    if (!root) return true;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    bool foundNull = false;

    while (front < rear) {
        struct TreeNode* node = queue[front++];

        if (node == NULL) {
            foundNull = true;
        } else {
            if (foundNull) return false; // non-null after null → not complete
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    return true;
}

// Check Min-Heap property recursively
bool isMinHeap(struct TreeNode* root) {
    if (!root) return true;

    if (root->left && root->val > root->left->val) return false;
    if (root->right && root->val > root->right->val) return false;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Combined check
bool checkMinHeap(struct TreeNode* root) {
    return isComplete(root) && isMinHeap(root);
}

int main() {
    /*
       Example tree:
             1
           /   \
          2     3
         / \   /
        4   5 6
       This satisfies Min-Heap property.
    */
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    if (checkMinHeap(root)) {
        printf("The tree is a Min-Heap.\n");
    } else {
        printf("The tree is NOT a Min-Heap.\n");
    }

    return 0;
}