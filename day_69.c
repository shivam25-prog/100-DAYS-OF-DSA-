//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// adjacency list
Node* adj[1000];

// add edge (directed or undirected depending on problem)
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// min-heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// priority queue (min-heap)
typedef struct {
    HeapNode* data;
    int size;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    h->size = 0;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent].dist > h->data[idx].dist) {
            swap(&h->data[parent], &h->data[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* h, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        smallest = idx;
        if (left < h->size && h->data[left].dist < h->data[smallest].dist)
            smallest = left;
        if (right < h->size && h->data[right].dist < h->data[smallest].dist)
            smallest = right;
        if (smallest != idx) {
            swap(&h->data[idx], &h->data[smallest]);
            idx = smallest;
        } else break;
    }
}

void push(MinHeap* h, int vertex, int dist) {
    h->data[h->size].vertex = vertex;
    h->data[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->data[0];
    h->data[0] = h->data[--h->size];
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap* h) {
    return h->size == 0;
}

// Dijkstra’s Algorithm
void dijkstra(int V, int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap* h = createHeap(V * V);
    push(h, src, 0);

    while (!isEmpty(h)) {
        HeapNode node = pop(h);
        int u = node.vertex;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;
    for (int i = 0; i < V; i++) adj[i] = NULL;

    // Example graph
    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);

    dijkstra(V, 0);

    return 0;
}