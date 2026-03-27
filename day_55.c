//Print the nodes visible when the binary tree is viewed from the right side.
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

// Function to print the right side view
void rightSideView(struct TreeNode* root) {
    if (!root) return;

    // Queue for BFS
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // If it's the last node in this level, print it
            if (i == levelSize - 1) {
                printf("%d ", node->val);
            }

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
    printf("\n");
}

int main() {
    // Build example tree: [1,2,3,null,5,null,4]
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    printf("Right Side View:\n");
    rightSideView(root);

    return 0;
}