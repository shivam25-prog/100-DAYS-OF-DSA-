//Using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>

#define N 100

int visited[N];

void dfs(int u, int graph[N][N], int n) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            dfs(v, graph, n);
        }
    }
}

int main() {
    int n = 4;

    // Adjacency matrix
    int graph[N][N] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };

    dfs(0, graph, n);

    // Check connectivity
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is connected\n");
    return 0;
}