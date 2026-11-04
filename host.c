#include <stdio.h>

int main()
{
    int n, a[10][10], visited[10] = {0};
    int queue[10], front = 0, rear = 0;
    int i, j, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source node: ");
    scanf("%d", &source);

    queue[rear++] = source;
    visited[source] = 1;

    printf("\nBroadcast Tree:\n");

    while(front < rear)
    {
        int current = queue[front++];

        for(i = 0; i < n; i++)
        {
            if(a[current][i] == 1 && visited[i] == 0)
            {
                printf("%d -> %d\n", current, i);

                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}