#include <stdio.h>

void findMax(int *arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < m; j++)
        {
            if (max <= *arr + i * n + j)
            {
                max = *arr + i * n + j;
            }
        }
        printf("Max element in row %d is %d\n", i + 1, max);
    }
}

int main()
{
    int m, n;
    printf("Enter row and column: ");
    scanf("%d %d", &n, &m);
    int arr[m][n];

    printf("Enter elements of matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findMax(&arr[0][0], n, m);
}