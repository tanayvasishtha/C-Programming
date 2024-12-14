/*7.1 Aim of the program: Given a directed graph G (V, E) and a starting vertex ‘s’.
● Determine the lengths of the shortest paths from the starting vertex ‘s’ to all other
vertices in the graph G using Dijkstra’s Algorithm.
● Display the shortest path from the given source ‘s’ to all other vertices.
Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have
varying distances or lengths. The graph G can be read from an input file “inDiAdjMat1.dat” that
contains non-negative cost adjacency matrix. The expected output could be as per the sample
format.*/


#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX // Infinity as the max integer value

void dijkstra(int graph[MAX][MAX], int n, int source);

int main() {
    int n, source;
    int graph[MAX][MAX];

    // Open the file containing the adjacency matrix
    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Reading the number of vertices from the user
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    // Reading the source vertex from the user
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);

    // Reading the adjacency matrix from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF; // Replace 0 with infinity for non-existing edges
        }
    }

    fclose(file);

    // Call Dijkstra's Algorithm
    dijkstra(graph, n, source - 1);

    return 0;
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX];   // The output array. dist[i] will hold the shortest distance from source to i
    int prev[MAX];   // Array to store the path
    int visited[MAX]; // visited[i] will be true if vertex i is included in the shortest path
    int count = 0;

    // Initialize distances to all vertices as infinity, and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;  // No predecessor for the initial vertex
    }

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int min = INF, u;

        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;  // Set predecessor
            }
    }

    // Print the results
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("%d\t%d\t\t%d\t", source + 1, i + 1, dist[i]);
            if (dist[i] == INF) {
                printf("No Path\n");
            } else {
                // Print the path
                int path[MAX], path_index = 0;
                int j = i;
                while (j != -1) {
                    path[path_index++] = j + 1;
                    j = prev[j];
                }
                for (int k = path_index - 1; k >= 0; k--) {
                    if (k == 0)
                        printf("%d\n", path[k]);
                    else
                        printf("%d->", path[k]);
                }
            }
        }
    }
}