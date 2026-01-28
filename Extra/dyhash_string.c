#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct friend {
    char name[50];
    struct friend* next;
};

struct friend *hashTable[SIZE];

int hashFunction(char *name) {
    int hash = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        hash = hash * 31 + name[i];
    }
    return hash % SIZE;
}

void insertFriend(char *name) {
    struct friend *newFriend = (struct friend *)malloc(sizeof(struct friend));
    strcpy(newFriend->name, name);
    newFriend->next = NULL;

    int index = hashFunction(name);

    if(hashTable[index] == NULL) {
        hashTable[index] = newFriend;
    } else {
        struct friend *temp = hashTable[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFriend;
    }
}

void displayHashTable() {
    for(int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct friend *temp = hashTable[i];
        while(temp != NULL) {
            printf("%s -> ", temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    char name[50];
    int choice;

    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    do {
        printf("\nMenu\n");
        printf("1. Hash an element in the table\n");
        printf("2. Display the hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of your friend to hash: ");
                scanf("%s", name);
                insertFriend(name);
                printf("\nName hashed successfully...\n");
                break;
            case 2:
                displayHashTable();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}
