/**
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *create(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(Node *root)
{
    printf("Inorder is: ");
    inorder(root);
    printf("\n");
}

int main()
{
    Node *root = NULL;
    int data, c;

    printf("MENU\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Display\n6.Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            display(root);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid input\n");
        }
    }
}


**/
