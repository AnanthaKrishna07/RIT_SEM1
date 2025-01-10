#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX];
int n; // Number of vertices

void DFS(int vertex) {
    printf("%d ", vertex); // Print the current vertex
    visited[vertex] = 1;   // Mark the current vertex as visited

    // Loop through all vertices to check adjacency
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) { // Check for unvisited connected vertices
            DFS(i); // Recursive call to visit the connected vertex
        }
    }
}

int main() {
    int src;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]); // Input adjacency matrix values (0 or 1)
        }
    }

    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input starting vertex for DFS
    printf("Enter the starting vertex: ");
    scanf("%d", &src);

    printf("DFS Traversal starting from vertex %d:\n", src);
    DFS(src);

    return 0;
}
