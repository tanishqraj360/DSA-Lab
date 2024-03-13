#include <stdio.h>

int findMax(int *a, int *b, int *c)
{
    if (*a > *b && *b > *c)
    {
        return *a;
    }
    else if (*b > *c && *b > *a)
    {
        return *b;
    }
    else
    {
        return *c;
    }
}

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    int max = findMax(&a, &b, &c);

    printf("Max: %d", max);
}