#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int w, int wt[], int val[], int n)
{
    int k[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;

            else if (wt[i - 1] <= j)
                k[i][j] = max(val[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);

            else
                k[i][j] = k[i - 1][j];
        }
    }

    return k[n][w];
}

int main()
{
    int n, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter knapsack capacity: ");
    scanf("%d", &w);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    int result = knapsack(w, wt, val, n);

    printf("Maximum value in knapsack = %d\n", result);

    return 0;
}