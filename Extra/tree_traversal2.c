#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main() {
    struct node* root = NULL;
    int num, i, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    printf("Enter the elements: ");
    for (i = 0; i < num; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Preorder traversal of the BST is: ");
    preorder_traversal(root);

    return 0;
}

