//Using DFS or BFS, count number of connected components.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   // adjacency matrix
int visited[MAX];
int V;                 // number of vertices

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int countConnectedComponents() {
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    int components = countConnectedComponents();
    printf("Number of connected components: %d\n", components);

    return 0;
}