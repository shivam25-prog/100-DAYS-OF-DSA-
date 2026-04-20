#include <stdio.h>

#define N 100
#define INF 999999

int main() {
    int n = 5;   // number of vertices
    int src = 0; // source vertex

    int graph[N][N] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };

    int dist[N];
    int visited[N] = {0};

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Dijkstra
    for (int count = 0; count < n - 1; count++) {

        int min = INF, u = -1;

        // Find minimum distance vertex
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}