#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int stack[SIZE];
int top = -1;

void push(int val)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return stack[top--];
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nSTACK OPERATION\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            int result = pop();
            printf("Data deleted: %d", result);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Error! Invalid Input\n");
            break;
        }
    }
    return 0;
}