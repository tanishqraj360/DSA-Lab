#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp = NULL, *new_node, *temp1;

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

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Linked List: \n");
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void deleteatkey()
{
    int key;
    printf("Enter value to be deleted: ");
    scanf("%d", &key);

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (head->data == key)
        {
            printf("Data to be deleted: %d", head->data);
            temp = head;
            head = head->next;
            free(temp);
            return;
        }
        temp = head;
        while (temp != NULL && temp->next->data != key)
        {
            temp = temp->next;
        }
        if (temp->next->data == key)
        {
            printf("Data to be deleted: %d", temp->next->data);
            temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }
        else
        {
            printf("Key value not found\n");
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nLINKED LIST\n");
        printf("1. Insert at first\n");
        printf("2. Delete at value\n");
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
            deleteatkey();
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