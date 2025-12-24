/**
#include <stdio.h>

#define MAX 10

int a[MAX][MAX];
int vis[MAX];
int n;

void dfs(int v)
{
    int j;
    vis[v] = 1;
    printf("%d ", v);
    for (j = 0; j < n; j++)
    {
        if (a[v][j] == 1 && vis[j] == 0)
            dfs(j);
    }
}

int main()
{
    int i, j, start, count = 0;

    printf("Enter total number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        vis[i] = 0;

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);
    printf("\n");

    for (i = 0; i < n; i++)
        if (vis[i] == 1)
            count++;

    if (count == n)
        printf("Graph is connected\n");
    else
        printf("Not a connected graph\n");

    return 0;
}

**/
