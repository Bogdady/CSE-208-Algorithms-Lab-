#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX 50

int arr[MAX];
int n;

long long comparisons = 0;
long long swaps = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    swaps++;
}

void delay()
{
    Sleep(0000);
}

void printArray()
{
    int i;

    printf("\nArray: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void visualize()
{
    system("cls");

    printf("\033[1;36m========== Sorting Algorithm Visualizer ==========\033[0m\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%2d | ", arr[i]);

        for (int j = 0; j < arr[i]; j++)
            printf("\033[0;30;44m-\033[0m");

        printf("\n");
    }

    printf("\nComparisons : %lld", comparisons);
    printf("\nSwaps/Moves : %lld\n", swaps);

    delay();
}

void bubbleSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;

                visualize();
            }
        }

        if (swapped == 0)
            break;
    }
}

void selectionSort()
{
    int minIndex;

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
            visualize();
        }
    }
}

void insertionSort()
{
    int key;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swaps++;

                visualize();
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
        swaps++;
        visualize();
    }
}

void merge(int left, int mid, int right)
{
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[MAX], R[MAX];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        comparisons++;

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            swaps++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            swaps++;
            j++;
        }

        k++;
        visualize();
    }

    while (i < n1)
    {
        arr[k] = L[i];
        swaps++;
        i++;
        k++;

        visualize();
    }

    while (j < n2)
    {
        arr[k] = R[j];
        swaps++;
        j++;
        k++;

        visualize();
    }
}

void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            visualize();
        }
    }

    swap(&arr[i + 1], &arr[high]);
    visualize();

    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void inputArray()
{
    int i;

    printf("\nEnter number of elements (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid Size!\n");
        exit(0);
    }

    printf("\nEnter Elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void randomArray()
{
    int i;

    printf("\nEnter number of elements (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid Size!\n");
        exit(0);
    }

    srand(time(NULL));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 20 + 1;

    printf("\nRandom Array Generated.\n");
}

void resetStats()
{
    comparisons = 0;
    swaps = 0;
}

void showComplexity(int choice)
{
    printf("\n\033[1;31m====================================\033[0m\n");
    switch (choice)
    {
    case 1:
        printf("\033[1;31mBubble Sort\033[0m\n");
        printf("\033[1;30mBest Case    : O(n)\033[0m\n");
        printf("\033[1;30mAverage Case : O(n^2)\033[0m\n");
        printf("\033[1;30mWorst Case   : O(n^2)\033[0m\n");
        printf("\033[1;30mSpace        : O(1)\033[0m\n");
        break;

    case 2:
        printf("\033[1;32mSelection Sort\033[0m\n");
        printf("\033[1;30mBest Case    : O(n^2)\033[0m\n");
        printf("\033[1;30mAverage Case : O(n^2)\033[0m\n");
        printf("\033[1;30mWorst Case   : O(n^2)\033[0m\n");
        printf("\033[1;30mSpace        : O(1)\033[0m\n");
        break;

    case 3:
        printf("\033[1;34mInsertion Sort\033[0m\n");
        printf("\033[1;30mBest Case    : O(n)\033[0m\n");
        printf("\033[1;30mAverage Case : O(n^2)\033[0m\n");
        printf("\033[1;30mWorst Case   : O(n^2)\033[0m\n");
        printf("\033[1;30mSpace        : O(1)\033[0m\n");
        break;

    case 4:
        printf("\033[1;35mMerge Sort\033[0m\n");
        printf("\033[1;30mBest Case    : O(n log n)\033[0m\n");
        printf("\033[1;30mAverage Case : O(n log n)\033[0m\n");
        printf("\033[1;30mWorst Case   : O(n log n)\033[0m\n");
        printf("\033[1;30mSpace        : O(n)\033[0m\n");
        break;

    case 5:
        printf("\033[1;36mQuick Sort\033[0m\n");
        printf("\033[1;30mBest Case    : O(n log n)\033[0m\n");
        printf("\033[1;30mAverage Case : O(n log n)\033[0m\n");
        printf("\033[1;30mWorst Case   : O(n^2)\033[0m\n");
        printf("\033[1;30mSpace        : O(log n)\033[0m\n");
        break;
    }
    printf("\033[1;31m====================================\033[0m\n");
}

int main()
{

    while (1)
    {
        system("cls");
        printf("\033[1;36m========== Sorting Algorithm Visualizer ==========\033[0m\n");
        printf("\n1. Start Visualization");
        printf("\n2. Exit");
        printf("\nChoose: ");
        int choice1;
        scanf("%d", &choice1);
        if (choice1 == 2)
        {
            printf("\nExiting...\n");
            break;
        }
        int choice;
        int inputChoice;

        printf("\n1. Manual Input");
        printf("\n2. Random Array");

        printf("\nChoose: ");
        scanf("%d", &inputChoice);

        if (inputChoice == 1)
            inputArray();
        else
            randomArray();

        printf("\nOriginal ");
        printArray();

        printf("\nChoose Sorting Algorithm\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");

        printf("\nChoice: ");
        scanf("%d", &choice);
        resetStats();

        clock_t start = clock();
        switch (choice)
        {
        case 1:
            bubbleSort();
            break;

        case 2:
            selectionSort();
            break;

        case 3:
            insertionSort();
            break;

        case 4:
            mergeSort(0, n - 1);
            break;

        case 5:
            quickSort(0, n - 1);
            break;

        default:
            printf("Invalid Choice!");
            exit(0);
        }
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\n\033[1;32mSorting Completed!\033[0m\n");

        printArray();

        printf("\nComparisons : %lld", comparisons);
        printf("\nSwaps/Moves : %lld\n", swaps);
        printf("\nExecution Time : %.6f seconds\n", timeTaken);

        showComplexity(choice);

        printf("\nPress Enter to return to the main menu...");
        getchar();
        getchar();
    }
    return 0;
}