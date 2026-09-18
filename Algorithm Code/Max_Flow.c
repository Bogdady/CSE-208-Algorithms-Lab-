#include <stdio.h>
#define MAX 10
int graph[MAX][MAX], parent[MAX], visited[MAX];
int n, source, sink;

int bfs(int source, int sink)
{
    int queue[MAX], front = 0, rear = 0;
    int i, u;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (front < rear)
    {
        /* code */
        u = queue[front++];
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 && graph[u][i] > 0)
            {
                queue[rear++] = i;
                parent[i] = u;
                visited[i] = 1;
            }
        }
    }
    return visited[sink];
}

int fordfulkerson(int source, int sink)
{
    int maxflow = 0, pathflow, u, v;

    while (bfs(source, sink))
    {

        pathflow = 99999;
        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            if (graph[u][v] < pathflow)
                pathflow = graph[u][v];
                }

        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            graph[u][v] -= pathflow;
            graph[v][u] += pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}

int main()
{
    printf("Enter number of vertex: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter vertices: ");

    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    printf("Enter Source node: ");
    scanf("%d", &source);
    printf("Enter Sink: ");
    scanf("%d", &sink);
    printf("Maximum Flow: %d\n", fordfulkerson(source, sink));

    return 0;
}