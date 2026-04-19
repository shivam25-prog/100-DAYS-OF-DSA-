//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>

#define N 100
#define INF 999999

int main() {
    int n = 4;

    // Adjacency matrix (0 means no edge)
    int graph[N][N] = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 0},
        {6, 8, 0, 0}
    };

    int selected[N] = {0}; // MST set
    int edges = 0;
    int totalWeight = 0;

    selected[0] = 1; // start from node 0

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("Edge: %d - %d  Weight: %d\n", x, y, graph[x][y]);

        totalWeight += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("Total MST Weight = %d\n", totalWeight);

    return 0;
}