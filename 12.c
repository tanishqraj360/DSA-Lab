#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int val;
    if (rear == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter data: ");
        scanf("%d", &val);
        queue[++rear] = val;
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Deleted data: %d", queue[front++]);
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Elements of Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}

int main()
{
    while (1)
    {
        printf("\n-----------MENU----------\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        int ch, n;
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Input");
            break;
        }
    }
}