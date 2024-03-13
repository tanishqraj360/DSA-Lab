#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *create()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->left = new_node->right = NULL;
}

void insert(struct node *root, struct node *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            insert(root->left, new_node);
        }
    }
    else if (new_node->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            insert(root->right, new_node);
        }
    }
    else
    {
        printf("Data already exists in BST\n");
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    struct node *new_node = NULL;
    int ch, data;
    while (1)
    {
        printf("\n-----------------MENU--------------------");
        printf("\n 1 - Insert node in BST");
        printf("\n 2 - Display in Preorder");
        printf("\n 3 - Display in Inorder");
        printf("\n 4 - Display in Postorder");
        printf("\n 5 - Exit\n");
        printf("------------------------------------------\n");
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            new_node = create();
            printf("\n Enter data: ");
            scanf("%d", &new_node->data);
            if (root == NULL)
            {
                root = new_node;
            }
            else
            {
                insert(root, new_node);
            }
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Error! Invalid Input\n");
        }
    }
    return 0;
}