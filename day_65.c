// Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];   // array of adjacency lists
int visited[MAX]; // visited array

// utility to add edge
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // since undirected, add reverse edge
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS with parent tracking
int dfs(int node, int parent) {
    visited[node] = 1;
    Node* temp = adj[node];

    while (temp != NULL) {
        int neigh = temp->vertex;
        if (!visited[neigh]) {
            if (dfs(neigh, node)) return 1;
        } else if (neigh != parent) {
            // visited neighbor not equal to parent → cycle
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// check cycle in all components
int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4;
    int E = 4;
    int edges[4][2] = {{0,1},{0,2},{1,2},{2,3}};

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