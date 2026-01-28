#include <stdio.h>
#include <stdlib.h>
#include "stcircular_queue.h"

void main()
{
    int choice, n;
    int i, x;
    printf("\n*****************Static Cicular Queue Implementation***********************\n");
    while (choice != 7)
    {
        printf("\n1.IsEmpty\n2.IsFull\n3.Enter element into a queue\n4.Delete Element from queue\n5.Print front element\n6.Display all elements\n7.Exit.\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isEmpty())
                printf("\nQueue is Empty.\n");
            else
                printf("\nQueue is not Empty.\n");
            break;
        case 2:
            if (isFull())
                printf("\nQueue is Full.\n");
            else
                printf("\nQueue is not Full.\n");
            break;
        case 3:
            printf("\nHow many elements you want in a queue?\n");
            scanf("%d", &n);
            printf("\nEnter %d elements.\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                enqueue(x);
            }
            break;
        case 4:
            printf("\nHow many elements you want to remove from a queue?\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                x = dequeue();
                printf("\n%d deleted from the queue.\n", x);
            }
            break;
        case 5:
            peek();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nEnter corrct choice.\n");
            break;
        }
    }
}