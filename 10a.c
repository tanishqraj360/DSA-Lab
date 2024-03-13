#include <stdio.h>
#include <string.h>
#define SIZE 50

char string[SIZE];
char reversed_string[SIZE];
char stack[SIZE];
int top = -1;

void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}

int main()
{
    printf("Enter String: ");
    scanf("%s", string);

    int len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        push(string[i]);
    }

    for (int i = 0; i < len; i++)
    {
        reversed_string[i] = pop();
    }

    if (strcmp(string, reversed_string) == 0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
}