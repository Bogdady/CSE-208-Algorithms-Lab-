#include <stdio.h>
#define v 5

int minkey(int key[], int visited[])
{
    int min = 9999, min_index;
    for (int j = 0; j < v; j++)
    {
        if (visited[j] == 0 && key[j] < min)
        {
            min = key[j];
            min_index = j;
        }
    }
    return min_index;
}

void primMST(int graph[5][5])
{
    int parent[5], key[5], visited[5];

    for (int i = 0; i < 5; i++)
    {
        key[i] = 9999;
        visited[i] = 0;
        parent[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < v; c++)
    {
        int u = minkey(key, visited);
        visited[u] = 1;

        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] && graph[u][j] < key[j] && visited[j] == 0)
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    int totalcost = 0;
    printf("Edge\t\tWeight\n");
    for (int i = 1; i < v; i++)
    {
        printf("%d--%d\t\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalcost = totalcost + graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalcost);
}

int main()
{

    int graph[5][5] = {
        {0, 2, 7, 4, 0},
        {2, 0, 3, 5, 0},
        {7, 3, 0, 1, 6},
        {4, 5, 1, 0, 5},
        {0, 0, 6, 5, 0}};

    primMST(graph);
    return 0;
}
