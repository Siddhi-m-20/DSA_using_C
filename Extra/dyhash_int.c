#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct{
    int data;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE] = { NULL };

int hash(int value) {
    return value % TABLE_SIZE;
}

void hash_table_insert(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    int index = hash(value);
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        printf("%d:", i);
        while (current != NULL) {
            printf("%d  ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int option, value;

    do {
        printf("\n MENU \n1.Hash an element \n2.Display the hash table \n3.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the integer value to be hashed: ");
                scanf("%d", &value);
                hash_table_insert(value);
                printf("Value hashed successfully\n");
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice entry!!!\n");
        }
    } while (option != 3);
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
