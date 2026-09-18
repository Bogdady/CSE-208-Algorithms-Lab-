#include <stdio.h>
#define size 100
int arr[size], arr2[size], arr3[size], n, m;

void merge(int arr[], int left, int mid, int right)
{
    int i = 0, j = 0, k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int u = 0; u < n1; u++)
        L[u] = arr[left + u];

    for (int v = 0; v < n1; v++)
        R[v] = arr[mid + 1 + v];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];

        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void new_merge(int L[], int R[])
{
    int i = 0, j = 0, k = 0;
    int n1 = n;
    int n2 = m;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr3[k++] = L[i++];

        else
            arr3[k++] = R[j++];
    }

    while (i < n1)
        arr3[k++] = L[i++];

    while (j < n2)
        arr3[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void print_sort_array(int arr[], int s)
{
    printf("Sorted array: ");
    for (int i = 0; i < s; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    while (1)
    {
        int c;
        printf("1) Merge Sort\n2) Add Elements and Sort\n3) Exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &c);

        if (c == 1)
        {
            printf("Enter Number of elemens: ");
            scanf("%d", &n);
            printf("Enter Numbers: ");

            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);

            merge_sort(arr, 0, n - 1);
            print_sort_array(arr, n);
        }
        if (c == 2)
        {
            printf("Enter Number of elemens: ");
            scanf("%d", &m);
            printf("Enter Numbers: ");

            for (int i = 0; i < m; i++)
                scanf("%d", &arr2[i]);

            merge_sort(arr2, 0, m - 1);
            new_merge(arr, arr2);
            print_sort_array(arr3, n + m);
        }
        if (c == 3)
            break;
    }
}