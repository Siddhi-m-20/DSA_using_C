#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left,right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    struct Node* root = NULL;
    int option, value;

    while (1) {
        printf("Choose an option:\n");
        printf("1 Insert a value in the tree\n");
        printf("2 Search for a value in the tree\n");
        printf("3 Print the tree in order\n");
        printf("4 Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter a value to search for: ");
                scanf("%d", &value);
                if (searchNode(root, value) == NULL) {
                    printf("Value not found in the tree\n");
                }
                else {
                    printf("Value found in the tree\n");
                }
                break;
            case 3:
                printf("Tree in order: ");
                printInOrder(root);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}
