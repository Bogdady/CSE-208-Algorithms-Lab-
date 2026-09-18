#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = high;

    for (int j = high; j > low; j--)
    {
        if (arr[j] > pivot)
        {
            swap(&arr[i], &arr[j]);
            i--;
        }
    }

    swap(&arr[i], &arr[low]);
    return i;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[10];
    printf("Enter numbers of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}