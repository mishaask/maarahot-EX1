#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V_MAX 100

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V_MAX][V_MAX], int src, int V) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int option;
    int graph[V_MAX][V_MAX] = {0};
    int V = 0;

    while (1) {
        printf("Options:\n1. Create new graph\n2. Modify existing graph\n3. Find shortest path\n4. Exit\nChoose an option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter the number of vertices in the graph: ");
            scanf("%d", &V);

            printf("Enter the weight of the edges in the adjacency matrix (enter 0 for no edge):\n");
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    printf("Edge weight from vertex %d to vertex %d: ", i, j);
                    scanf("%d", &graph[i][j]);
                    if (graph[i][j] < 0) {
                        printf("Invalid input. Please enter a non-negative weight or -1 for no edge.\n");
                        j--; // Repeat the input for this edge
                    }
                }
            }
        } else if (option == 2) {
            if (V == 0) {
                printf("Graph not yet created. Please create a new graph first.\n");
                continue;
            }

            int u, v, weight;
            printf("Enter the source vertex: ");
            scanf("%d", &u);
            printf("Enter the destination vertex: ");
            scanf("%d", &v);
            printf("Enter the new weight of the edge: ");
            scanf("%d", &weight);

            if (u < 0 || u >= V || v < 0 || v >= V || weight < 0) {
                printf("Invalid input. Please enter valid values.\n");
                continue;
            }

            graph[u][v] = weight;
            graph[v][u] = weight;
        } else if (option == 3) {
            if (V == 0) {
                printf("Graph not yet created. Please create a new graph first.\n");
                continue;
            }

            int src;
            printf("Enter the source vertex for shortest path calculation: ");
            scanf("%d", &src);

            if (src < 0 || src >= V) {
                printf("Invalid source vertex. Please enter a valid vertex.\n");
                continue;
            }

            dijkstra(graph, src, V);
        } else if (option == 4) {
            break;
        } else {
            printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}

