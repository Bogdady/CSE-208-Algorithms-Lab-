#include <stdio.h>
int parent[5];

int find_Parent(int p)
{
    while (parent[p] != p)
    {
        p = parent[p];
    }

    return p;
}

void kruskal(int graph[5][5])
{
    int minCost = 0;
    printf("Selected Edges:\n");

    for (int count = 0; count < 4;)
    {
        int min = 9999;
        int u = -1, v = -1;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (graph[i][j] != 0 && graph[i][j] < min)
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int a = find_Parent(u);
        int b = find_Parent(v);

        if (a != b)
        {
            printf("%d - %d = %d\n", u, v, min);

            minCost += min;
            parent[b] = a;
            count++;
        }

        graph[u][v] = 9999;
        graph[v][u] = 9999;
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main()
{
    int graph[5][5] = {
        {0, 2, 7, 4, 0},
        {2, 0, 3, 5, 0},
        {7, 3, 0, 1, 6},
        {4, 5, 1, 0, 5},
        {0, 0, 6, 5, 0}};

    for (int i = 0; i < 5; i++)
    {
        parent[i] = i;
    }

    kruskal(graph);

    return 0;
}