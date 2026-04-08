//Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];   // adjacency list
int visited[MAX]; // visited array
int stack[MAX];   // stack to store order
int top = -1;

// utility to add edge (directed)
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;
    Node* temp = adj[node];
    while (temp) {
        int neigh = temp->vertex;
        if (!visited[neigh]) {
            dfs(neigh);
        }
        temp = temp->next;
    }
    stack[++top] = node; // push after visiting neighbors
}

// Function to print topological order
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int V = 6; // number of vertices
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}