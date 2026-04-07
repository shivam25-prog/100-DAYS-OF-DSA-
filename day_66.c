//Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];   // adjacency list
int visited[MAX]; // visited array
int recStack[MAX]; // recursion stack array

// utility to add edge (directed)
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS with recursion stack
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    Node* temp = adj[node];
    while (temp != NULL) {
        int neigh = temp->vertex;
        if (!visited[neigh]) {
            if (dfs(neigh)) return 1;
        } else if (recStack[neigh]) {
            // back edge found → cycle
            return 1;
        }
        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// check cycle in all components
int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4;
    int E = 4;
    int edges[4][2] = {{0,1},{1,2},{2,3},{3,1}}; // cycle present

    // initialize adjacency list
    for (int i = 0; i < V; i++) adj[i] = NULL;

    // build graph
    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    if (hasCycle(V))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}