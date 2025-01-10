#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];  // Adjacency matrix
int visited[MAX];     // Visited array
int queue[MAX];       // Queue for BFS
int front = 0, rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");
    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}
