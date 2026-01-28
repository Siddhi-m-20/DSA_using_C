#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 256
#define TABLE_SIZE 26 * 2

typedef struct
{
    char name[MAX_NAME];
} person;

person hash_table[TABLE_SIZE];

int hash(char *name)
{
    int hash_value = toupper(name[0]) - 'A';
    return hash_value % TABLE_SIZE;
}

int hash_table_insert(person p)
{
    int index = hash(p.name);
    int original_index = index;

    while (hash_table[index].name[0] != '\0')
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index)
        {
            return 0;
        }
    }

    hash_table[index] = p;
    return 1;
}

void display()
{
    printf("\nHash Table:");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("\n%d\t%s", i, hash_table[i].name);
    }
    printf("\n");
}

int main()
{
    int option;
    person p;

    do
    {
        printf("\n MENU \n1.Hash an element \n2.Display the hash table \n3.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the name of your friend to be inserted: ");
            scanf("%s", p.name);
            if (hash_table_insert(p))
            {
                printf("Name hashed successfully\n");
            }
            else
            {
                printf("Table is full, cannot hash name\n");
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