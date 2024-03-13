#include <stdio.h>
#define SIZE 10

int largest(int arr[], int n)
{
    int large = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    return large;
}

void radix_sort(int arr[], int n)
{
    int bucket[SIZE][SIZE], bcount[SIZE];
    int NOD = 0, rem, divisor = 1;
    int large = largest(arr, n);
    while (large > 0)
    {
        NOD++;
        large = large / SIZE;
    }

    for (int pass = 0; pass < NOD; pass++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            bcount[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            rem = (arr[i] / divisor) % SIZE;
            bucket[rem][bcount[rem]] = arr[i];
            bcount[rem] += 1;
        }
        int i = 0;
        for (int k = 0; k < SIZE; k++)
        {
            for (int j = 0; j < bcount[k]; j++)
            {
                arr[i++] = bucket[k][j];
            }
        }
        divisor *= SIZE;
    }
}

void main()
{
    int arr[SIZE], n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radix_sort(arr, n);
    printf("The Sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}