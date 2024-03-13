#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *new_node, *next, *current, *prev;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
}

void insertatfirst()
{
    if (head == NULL)
    {
        create();
        head = new_node;
    }
    else
    {
        create();
        new_node->next = head;
        head = new_node;
    }
}

void reverse()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("Linked list: \n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nLINKED LIST\n");
        printf("1. Insert at First\n");
        printf("2. Reverse\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertatfirst();
            break;
        case 2:
            reverse();
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