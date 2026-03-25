//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue node for BFS
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
    struct QNode* next;
};

// Simple queue implementation
struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    return temp;
}

// Map node for storing HD -> list of values
struct MapNode {
    int hd;
    int values[100];
    int count;
    struct MapNode* next;
};

// Insert into map
void insertMap(struct MapNode** head, int hd, int value) {
    struct MapNode* temp = *head;
    while (temp) {
        if (temp->hd == hd) {
            temp->values[temp->count++] = value;
            return;
        }
        temp = temp->next;
    }
    // If not found, create new
    struct MapNode* newMap = (struct MapNode*)malloc(sizeof(struct MapNode));
    newMap->hd = hd;
    newMap->values[0] = value;
    newMap->count = 1;
    newMap->next = *head;
    *head = newMap;
}

// Print vertical order
void printVerticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q = {NULL, NULL};
    enqueue(&q, root, 0);

    struct MapNode* map = NULL;

    while (q.front) {
        struct QNode* qnode = dequeue(&q);
        insertMap(&map, qnode->hd, qnode->node->data);

        if (qnode->node->left)
            enqueue(&q, qnode->node->left, qnode->hd - 1);
        if (qnode->node->right)
            enqueue(&q, qnode->node->right, qnode->hd + 1);

        free(qnode);
    }

    // Print map (unsorted by HD, but can be sorted if needed)
    struct MapNode* temp = map;
    while (temp) {
        printf("HD %d: ", temp->hd);
        for (int i = 0; i < temp->count; i++)
            printf("%d ", temp->values[i]);
        printf("\n");
        temp = temp->next;
    }
}

// Example usage
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printVerticalOrder(root);
    return 0;
}