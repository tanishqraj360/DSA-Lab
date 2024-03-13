#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *temp = NULL, *head = NULL, *new_node;

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

void search()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);
    int i = 0;
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
        i++;
    }
    if (temp->data == key)
    {
        printf("Data %d is at index %d\n", key, i + 1);
    }
    else
    {
        printf("Key value not found\n");
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
    printf("Linked list: \n");
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
        printf("2. Search for Node\n");
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
            search();
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