#include <stdio.h>

#define MAX_SIZE 25

struct HashNode {
    int num;
};

struct HashNode hash_table[MAX_SIZE];

int hash(int number) {
    return (number + 20) % MAX_SIZE;
}

int hash_table_insert(int number) {
    int index = hash(number);
    int original_index = index;
    
    while (hash_table[index].num != 0) {
        index = (index + 1) % MAX_SIZE;
        if (index == original_index) {
            return 0;
        }
    }

    hash_table[index].num = number;
    return 1;
}

void display() {
    printf("\nHash Table:");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("\n%d\t\t\t%d", i, hash_table[i].num);
    }
    printf("\n");
}

int main() {
    int option, number;
    for (int i = 0; i < MAX_SIZE; i++) {
        hash_table[i].num = 0;
    }

    do {
        printf("\n MENU \n1.Hash an element \n2.Display the hash table \n3.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &number);
                if (hash_table_insert(number)) {
                    printf("Number hashed successfully\n");
                } else {
                    printf("Table is full, cannot hash number\n");
                }
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

    return 0;
}