#include <stdio.h>

#define MAX 10

int a[MAX][MAX];
int vis[MAX];
int n;

void bfs(int v)
{
    int q[MAX];
    int f = 0, r = 0;
    int u, i;

    q[r] = v;
    vis[v] = 1;

    while (f <= r)
    {
        u = q[f++];
        printf("%d ", u + 1);

        for (i = 0; i < n; i++)
        {
            if (a[u][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter total number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        vis[i] = 0;

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &start);

    printf("Nodes from source node: ");
    bfs(start - 1);
    printf("\n");

    return 0;
}
