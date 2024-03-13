#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *head = NULL, *temp, *new_node;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
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
        head->prev = new_node;
        head = new_node;
    }
}

void insertatkey()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    if (head->data == key)
    {
        insertatfirst();
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->data == key)
    {
        create();
        new_node->next = temp;
        temp->prev->next = new_node;
        new_node->prev = temp->prev;
        temp->prev = new_node;
    }
    else
    {
        printf("Key not found\n");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Linked List: \n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nLINKED LIST\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Key\n");
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
            insertatkey();
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