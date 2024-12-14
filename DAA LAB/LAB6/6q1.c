/*6.1 Aim of the program: Given an undirected weighted connected graph G(V, E) and starring
vertex ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and apply Prim’s algorithm
to
● Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix of ‘T’.
● Display total cost of the minimum spanning tree T.
Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have
varying weight. The graph G can be read from an input file “inUnAdjMat.dat” that contains cost
adjacency matrix. The expected output could be displayed as the cost adjacency matrix of the
minimum spanning tree and total cost of the tree.*/
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX  // Representing Infinity as max int

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, min_index;
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[10][10], int vertices) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[10][10], int vertices) {
    int parent[vertices]; // Array to store the constructed MST
    int key[vertices];    // Key values to pick minimum weight edge
    bool mstSet[vertices]; // To represent vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    key[0] = 0;      // Make key 0 so that this vertex is picked first
    parent[0] = -1;  // First node is always the root of MST

    // The MST will have vertices - 1 edges
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, vertices);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print the MST and its total weight
    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    FILE *file;
    
    // Open the input file
    file = fopen("inUnAdjMat.dat", "r");
    
    if (file != NULL) {
        printf("Error Reading File\n");
        return 0;
    }

    // Read the number of vertices
    fscanf(file, "%d", &vertices);

    int graph[10][10];

    // Read the adjacency matrix from the file
    printf("Reading adjacency matrix from file:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF; // No direct edge between nodes
            }
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Close the file after reading
    fclose(file);

    // Apply Prim's Algorithm
    primMST(graph, vertices);

    return 0;
}