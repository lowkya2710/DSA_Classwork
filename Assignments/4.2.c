#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
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

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* minimum(struct node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node *root, int x) {
    struct node *temp;

    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &x);

    root = deleteNode(root, x);

    printf("Inorder after deletion: ");
    inorder(root);

    return 0;
}