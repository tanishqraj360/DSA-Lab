#include <stdio.h>
#include <stdlib.h>

int count = 1;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *new_node;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = new_node;
    count++;
}

void insert()
{

    if (head == NULL)
    {
        create();
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        create();
        temp->next = new_node;
        new_node->next = head;
    }
}

void delete()
{
    temp = head;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        printf("Data to be Deleted: %d", head->data);
        if (temp == head)
        {
            free(temp);
            head = NULL;
        }
        else
        {
            temp->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }
        count--;
    }
}

void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements of queue\n");
        while (temp->next != head)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\n ", temp->data);
    }
}

int main()
{
    while (1)
    {
        printf("\n----------MENU----------\n");
        printf("\n1.Insert\n2.Delete\n3. Display\n4. Exit\n");
        int ch;
        printf("\nEnter choice: ");
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
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
}