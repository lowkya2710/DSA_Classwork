#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
        return root;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node *root, int x)
{
    if (root == NULL)
        return 0;

    if (root->data == x)
        return 1;

    if (x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int main()
{
    struct node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &x);

    if (search(root, x))
        printf("Value found");
    else
        printf("Value not found");

    return 0;
}