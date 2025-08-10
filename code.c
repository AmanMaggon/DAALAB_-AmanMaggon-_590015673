#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int Binary_Searching(int arr[], int n, int k)
{
    int Low = 0, High = n - 1;
    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (arr[Mid] == k)
        {
            return Mid;
        }
        else if (arr[Mid] < k)
        {
            Low = Mid + 1;
        }
        else
        {
            High = Mid - 1;
        }
    }
    return -1;
}

int Int_Comparision(const void *a, const void *b)
{
    // Correct comparison for integers:
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

double Time_Measurement(int arr[], int n, int k, int iterations)
{
    clock_t start = clock();
    int result = -1;
    for (int i = 0; i < iterations; ++i)
    {
        if (n > 0)
            result = Binary_Searching(arr, n, k);
        else
            result = -1;
    }
    clock_t end = clock();
    if (result == -2)
        printf(""); // prevent full optimization
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1e9 / iterations; // time in ns per search
}

double Precise_Time_Measurement(int arr[], int n, int k, int iterations)
{
    double total = 0.0;
    int runs = 5;
    for (int i = 0; i < runs; ++i)
        total += Time_Measurement(arr, n, k, iterations);
    return total / runs;
}

void Random_ArrayFilling(int arr[], int n, int maxVal)
{
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % maxVal + 1;
}

void Best_Case(FILE *fp)
{
    printf("Testing Best Cases:\n");

    int arr1[5];
    Random_ArrayFilling(arr1, 5, 1000);
    qsort(arr1, 5, sizeof(int), Int_Comparision);
    double t = Precise_Time_Measurement(arr1, 5, arr1[2], 7000000);
    printf("Best Case 1 Time: %.3f ns\n", t);
    fprintf(fp, "Best,5,%f\n", t);

    int arr2[15];
    Random_ArrayFilling(arr2, 15, 1000);
    qsort(arr2, 15, sizeof(int), Int_Comparision);
    t = Precise_Time_Measurement(arr2, 15, arr2[7], 7000000);
    printf("Best Case 2 Time: %.3f ns\n", t);
    fprintf(fp, "Best,15,%f\n", t);

    int arr3[100];
    Random_ArrayFilling(arr3, 100, 1000);
    qsort(arr3, 100, sizeof(int), Int_Comparision);
    t = Precise_Time_Measurement(arr3, 100, arr3[49], 7000000);
    printf("Best Case 3 Time: %.3f ns\n", t);
    fprintf(fp, "Best,100,%f\n", t);

    int arr4[6];
    Random_ArrayFilling(arr4, 6, 1000);
    qsort(arr4, 6, sizeof(int), Int_Comparision);
    t = Precise_Time_Measurement(arr4, 6, arr4[2], 7000000);
    printf("Best Case 4 Time: %.3f ns\n", t);
    fprintf(fp, "Best,6,%f\n", t);

    int arr5[7];
    Random_ArrayFilling(arr5, 7, 1000);
    qsort(arr5, 7, sizeof(int), Int_Comparision);
    t = Precise_Time_Measurement(arr5, 7, arr5[3], 7000000);
    printf("Best Case 5 Time: %.3f ns\n", t);
    fprintf(fp, "Best,7,%f\n", t);
}

void Worst_Case(FILE *fp)
{
    printf("\nTesting Worst Cases:\n");

    int arr1[5];
    Random_ArrayFilling(arr1, 5, 1000);
    qsort(arr1, 5, sizeof(int), Int_Comparision);
    double t = Time_Measurement(arr1, 5, arr1[4] + 100, 5000000);
    printf("Worst Case 1 Time: %.3f ns\n", t);
    fprintf(fp, "Worst,5,%f\n", t);

    int arr2[15];
    Random_ArrayFilling(arr2, 15, 1000);
    qsort(arr2, 15, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr2, 15, arr2[14] + 100, 5000000);
    printf("Worst Case 2 Time: %.3f ns\n", t);
    fprintf(fp, "Worst,15,%f\n", t);

    int arr3[100];
    Random_ArrayFilling(arr3, 100, 1000);
    qsort(arr3, 100, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr3, 100, arr3[99] + 100, 3000000);
    printf("Worst Case 3 Time: %.3f ns\n", t);
    fprintf(fp, "Worst,100,%f\n", t);

    int arr4[100];
    Random_ArrayFilling(arr4, 100, 1000);
    qsort(arr4, 100, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr4, 100, arr4[0], 3000000);
    printf("Worst Case 4 Time: %.3f ns\n", t);
    fprintf(fp, "Worst,100,%f\n", t);

    int arr5[100];
    Random_ArrayFilling(arr5, 100, 1000);
    qsort(arr5, 100, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr5, 100, arr5[99], 3000000);
    printf("Worst Case 5 Time: %.3f ns\n", t);
    fprintf(fp, "Worst,100,%f\n", t);
}

void Average_Case(FILE *fp)
{
    printf("\nTesting Average Cases:\n");

    int arr1[5];
    Random_ArrayFilling(arr1, 5, 1000);
    qsort(arr1, 5, sizeof(int), Int_Comparision);
    double t = Time_Measurement(arr1, 5, arr1[1], 5000000);
    printf("Average Case 1 Time: %.3f ns\n", t);
    fprintf(fp, "Average,5,%f\n", t);

    int arr2[15];
    Random_ArrayFilling(arr2, 15, 1000);
    qsort(arr2, 15, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr2, 15, arr2[10], 5000000);
    printf("Average Case 2 Time: %.3f ns\n", t);
    fprintf(fp, "Average,15,%f\n", t);

    int arr3[100];
    Random_ArrayFilling(arr3, 100, 1000);
    qsort(arr3, 100, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr3, 100, arr3[70], 3000000);
    printf("Average Case 3 Time: %.3f ns\n", t);
    fprintf(fp, "Average,100,%f\n", t);

    int arr4[6];
    Random_ArrayFilling(arr4, 6, 1000);
    qsort(arr4, 6, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr4, 6, arr4[3], 5000000);
    printf("Average Case 4 Time: %.3f ns\n", t);
    fprintf(fp, "Average,6,%f\n", t);

    int arr5[7];
    Random_ArrayFilling(arr5, 7, 1000);
    qsort(arr5, 7, sizeof(int), Int_Comparision);
    t = Time_Measurement(arr5, 7, arr5[4], 5000000);
    printf("Average Case 5 Time: %.3f ns\n", t);
    fprintf(fp, "Average,7,%f\n", t);
}

void Edge_Case(FILE *fp)
{
    printf("\nTesting Edge Cases:\n");

    double t = Time_Measurement(NULL, 0, 10, 10000000);
    printf("Edge Case 1 (Empty Array): %.3f ns\n", t);
    fprintf(fp, "Edge,0,%f\n", t);

    int edgeCase2[1] = {42};
    t = Time_Measurement(edgeCase2, 1, 42, 10000000);
    printf("Edge Case 2 (Single Element Present): %.3f ns\n", t);
    fprintf(fp, "Edge,1,%f\n", t);

    int edgeCase3[1] = {42};
    t = Time_Measurement(edgeCase3, 1, 99, 10000000);
    printf("Edge Case 3 (Single Element Not Present): %.3f ns\n", t);
    fprintf(fp, "Edge,1,%f\n", t);

    int edgeCase4[5] = {1, 2, 3, 4, 5};
    t = Time_Measurement(edgeCase4, 5, 1, 5000000);
    printf("Edge Case 4 (Element at First Position): %.3f ns\n", t);
    fprintf(fp, "Edge,5,%f\n", t);

    int edgeCase5[5] = {1, 2, 3, 4, 5};
    t = Time_Measurement(edgeCase5, 5, 5, 5000000);
    printf("Edge Case 5 (Element at Last Position): %.3f ns\n", t);
    fprintf(fp, "Edge,5,%f\n", t);

    int edgeCase6[7] = {2, 2, 3, 3, 5, 5, 7};
    t = Time_Measurement(edgeCase6, 7, 3, 4000000);
    printf("Edge Case 6 (Potential Duplicates): %.3f ns\n", t);
    fprintf(fp, "Edge,7,%f\n", t);

    int edgeCase7[7] = {-5, -3, -1, 0, 1, 3, 7};
    t = Time_Measurement(edgeCase7, 7, -3, 4000000);
    printf("Edge Case 7 (Negative Values): %.3f ns\n", t);
    fprintf(fp, "Edge,7,%f\n", t);

    int edgeCase8[100];
    for (int i = 0; i < 100; ++i)
        edgeCase8[i] = i + 1;
    t = Time_Measurement(edgeCase8, 100, edgeCase8[0], 3000000);
    printf("Edge Case 8 (Large Array, First Position): %.3f ns\n", t);
    fprintf(fp, "Edge,100,%f\n", t);

    int edgeCase9[100];
    for (int i = 0; i < 100; ++i)
        edgeCase9[i] = i + 1;
    t = Time_Measurement(edgeCase9, 100, edgeCase9[99], 3000000);
    printf("Edge Case 9 (Large Array, Last Position): %.3f ns\n", t);
    fprintf(fp, "Edge,100,%f\n", t);

    int edgeCase10[100];
    for (int i = 0; i < 100; ++i)
        edgeCase10[i] = i + 1;
    t = Time_Measurement(edgeCase10, 100, 1000, 3000000);
    printf("Edge Case 10 (Large Array, Not Present): %.3f ns\n", t);
    fprintf(fp, "Edge,100,%f\n", t);
}

int main()
{
    srand((unsigned int)time(NULL));
    printf("Binary Search Performance Analysis (C Version):\n");

    FILE *fp = fopen("binary_search_times.csv", "w");
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "CaseType,ArraySize,Time(ns)\n");

    Best_Case(fp);
    Worst_Case(fp);
    Average_Case(fp);
    Edge_Case(fp);

    fclose(fp);
    return 0;
}
