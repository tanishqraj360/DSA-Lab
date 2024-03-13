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
    new_node->right = new_node->left = NULL;
    return new_node;
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

int countLeafNode(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeafNode(root->left) + countLeafNode(root->right);
    }
}

void printPath(struct node *root, int path[], int pathlen)
{
    if (root == NULL)
    {
        return;
    }

    path[pathlen] = root->data;
    pathlen++;

    if (root->left == NULL && root->right == NULL)
    {
        printf("Path: ");
        for (int i = 0; i < pathlen; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        printPath(root->left, path, pathlen);
        printPath(root->right, path, pathlen);
    }
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
        printf("\n 7 - Count Number of Leaf Nodes");
        printf("\n 12 - Print all Root to Leaf Paths");
        printf("\n 13 - Exit\n");
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
            printf("Number of Leaf Nodes: %d", countLeafNode(root));
            break;
        case 3:
            int path[100];
            int pathlen = 0;
            printPath(root, path, pathlen);
            break;
        }
    }
}