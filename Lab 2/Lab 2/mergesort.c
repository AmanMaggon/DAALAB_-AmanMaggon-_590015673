#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);
    int Left[n1];
    int Right[n2];
    for (int i = 0; i < n1; i++)
    {
        Left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Right[j] = arr[mid + 1 + j];
    }
    int left = 0, right = 0, k = low;
    while (left < n1 && right < n2)
    {
        if (Left[left] < Right[right])
        {
            arr[k] = Left[left];
            left++;
            k++;
        }
        else
        {
            arr[k] = Right[right];
            right++;
            k++;
        }
    }
    while (left < n1)
    {
        arr[k++] = Left[left++];
    }
    while (right < n2)
    {
        arr[k++] = Right[right++];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int mid = (high - low) / 2 + low;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Test Case 1 - Small Array
    {
        int arr[] = {87, 34, 21, 56, 12};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 1 (Small array) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 2 - Already Sorted Array
    {
        int arr[] = {11, 12, 13, 14, 15, 16, 17};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 2 (Already sorted) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 3 – Reverse sorted array
    {
        int arr[] = {9, 8, 7, 6, 5, 4, 3};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 3 (Reverse sorted) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 4 – Array with duplicates
    {
        int arr[] = {4, 2, 2, 4, 1, 1, 3, 3, 5, 5};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 4 (Duplicates) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 5 – Array with negative numbers
    {
        int arr[] = {-5, 10, -2, 7, -9, 0, 3, -1};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 5 (With negatives) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 6 – Odd-sized array
    {
        int arr[] = {11, 3, 7, 2, 9, 14, 1};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 6 (Odd-sized array, n=7) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 7 – Even-sized array
    {
        int arr[] = {20, 11, 5, 8, 14, 2, 9, 7, 3, 1};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 7 (Even-sized array, n=10) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    // Test Case 8 – Large random array (n=1000)
    {
        int n = 1000;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }
        printf("\n--- Test Case 8 (Large random array, n=1000) ---\n");
        merge_sort(arr, 0, n - 1);
        printf("Output (first 20 elements): ");
        for (int i = 0; i < 20; i++)
            printf("%d ", arr[i]);
        printf("...\n");
    }

    // Test Case 9 – Very large random array (n=10000)
    {
        int n = 10000;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100000;
        }
        printf("\n--- Test Case 9 (Very large random array, n=10000) ---\n");
        merge_sort(arr, 0, n - 1);
        printf("Output (first 20 elements): ");
        for (int i = 0; i < 20; i++)
            printf("%d ", arr[i]);
        printf("...\n");
    }

    // Test Case 10 – All elements same
    {
        int arr[] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
        int n = sizeof(arr) / sizeof(arr[0]);
        printf("\n--- Test Case 10 (All elements same) ---\n");
        printf("Input: ");
        printArray(arr, n);
        merge_sort(arr, 0, n - 1);
        printf("Output: ");
        printArray(arr, n);
    }

    return 0;
}
