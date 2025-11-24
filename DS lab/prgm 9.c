#include<stdio.h>
#include<stdlib.h>

// Minimum Spanning Tree - Kruskal algorithm
int i, j, k, u, v, rv, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];


int find(int u)
{
    while (parent[u])
        u = parent[u];
    return u;
}

 
void un(int ru, int rv)
{
    parent[rv] = ru;
    return;
}

void main()
{
    printf("\nEnter the no.of vertices:");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; 
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");

    while (ne < n)
    {
        min = 999;   


        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int ru = find(u);
        int rv = find(v);

        if (ru != rv)
        {
            un(ru, rv);   
            printf("%d edge(%d,%d) = %d\n", ne++,

