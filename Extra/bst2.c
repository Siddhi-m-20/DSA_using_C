#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
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

int count_non_leaf_nodes(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    } else {
        return 1 + count_non_leaf_nodes(root->left) + count_non_leaf_nodes(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int num, i, count;

    printf("Enter the number of nodes: ");
    scanf("%d",&num);

    printf("Enter the elements: ");
    for (i = 0;i < num; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    count = count_non_leaf_nodes(root);

    printf("The number of non-leaf nodes in the tree is %d\n", count);

    return 0;
}
