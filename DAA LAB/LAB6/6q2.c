/*6.2 Aim of the program: Given an undirected weighted connected graph G(V, E). Apply
Krushkal’s algorithm to
● Find the minimum spanning tree T(V, E’) and Display the selected edges of G.
● Display total cost of the minimum spanning tree T.
Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have
varying weight. The weight matrix of the graph can be represented from the user’s input in the
given format. The expected output could be the selected edge and the corresponding cost of the
edge as per the sample output.
Input Format:
● The first line contains two space-separated integers ‘n’ and ‘m’, the number of nodes
and edges in the graph.

● Each line ‘i’ of the ‘m’ subsequent lines contains three space-separated integers ‘u’, ‘v’
and ‘w’, that describe an edge (u, v) and weight ‘w’.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// A structure to represent an edge
struct Edge {
    int u, v, w;
};

// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

// A function to find set of an element i (uses path compression technique)
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->w - b1->w;
}

// Function to implement Kruskal's Algorithm
void Kruskal(struct Edge edges[], int n, int m) {
    struct Edge result[MAX]; // To store the resultant MST
    int e = 0; // Index variable for result[]
    int i = 0; // Index variable for sorted edges

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, m, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    struct subset *subsets = (struct subset *)malloc(n * sizeof(struct subset));

    // Create n subsets with single elements
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is n-1
    while (e < n - 1 && i < m) {
        // Pick the smallest edge. And increment the index for next iteration
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.u - 1);
        int y = find(subsets, next_edge.v - 1);

        // If including this edge does not cause a cycle, include it in the result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the result
    printf("Edge\tCost\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d--%d\t%d\n", result[i].u, result[i].v, result[i].w);
        totalWeight += result[i].w;
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    // Free memory
    free(subsets);
}

int main() {
    int n, m;
    struct Edge edges[MAX];

    // Input: Number of vertices (n) and edges (m)
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Input: Each edge (u, v) and its weight (w)
    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Apply Kruskal's algorithm
    Kruskal(edges, n, m);

    return 0;
}

