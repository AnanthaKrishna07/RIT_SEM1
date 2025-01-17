#include <stdio.h>

int n, i, u, v, a, b, e;
int cost[10][10], visited[10] = {0}, min, mincost = 0, ne = 1;

void main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 999;
        }
    }

    printf("\nEnter the edges with their weights (source destination weight):\n");
    for (i = 0; i < e; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        cost[src][dest] = weight;
        cost[dest][src] = weight; 
    }

    printf("\nCost matrix after input:\n");
    for (i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
	{
		if(cost[i][j]==999)
		{
		  printf("0 ");
		}
		else
		{
		  printf("%d ",cost[i][j]);
		}
	}
	printf("\n");
    }

    visited[0] = 1;
    printf("\n");

    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min && visited[i] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; 
    }

    printf("\n\nMinimum cost: %d\n", mincost);
}
