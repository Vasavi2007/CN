#include <stdio.h>

#define INF 9999

int main()
{
    int n, cost[10][10], dist[10];
    int visited[10] = {0};
    int i, j, count, min, u, v, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 for no edge):\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for(i = 0; i < n; i++)
        dist[i] = cost[src][i];

    dist[src] = 0;
    visited[src] = 1;

    for(count = 1; count < n; count++)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
        }
    }

    printf("\nShortest distances:\n");

    for(i = 0; i < n; i++)
        printf("From %d to %d = %d\n", src, i, dist[i]);

    return 0;
}