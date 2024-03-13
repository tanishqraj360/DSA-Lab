#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Eneter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    int flag = 0;
    int *ptr = arr;

    for (int i = 0; i < n; i++)
    {
        if (*ptr == key)
        {
            printf("Element found at position %d\n", i + 1);
            flag = 1;
            break;
        }
        else
        {
            ptr++;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}