//#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency matrix
int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void topologicalSort(int V) {
    // enqueue all vertices with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int topoOrder[MAX];

    while (!isEmpty()) {
        int u = dequeue();
        topoOrder[count++] = u;

        // reduce indegree of neighbors
        for (int v = 0; v < V; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // if count != V, graph has a cycle
    if (count != V) {
        printf("Graph has a cycle, topological sort not possible.\n");
        return;
    }

    // print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }

    topologicalSort(V);

    return 0;
}