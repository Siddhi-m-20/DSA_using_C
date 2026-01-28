#include<stdio.h>
#include<stdlib.h>
#include "stpriority_queue.h"
void main()
{   
    
    priority_queue queue;
    initializeQueue(&queue);
    int choice, n;
    int i, x,p;
    printf("\n*****************Static Priority Queue Implementation***********************\n");
    while (choice != 7)
    {   
        printf("\n1.IsEmpty\n2.IsFull\n3.Enter element into a queue\n4.Delete Element from queue\n5.Print front element\n6.Display all elements\n7.Exit.\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isEmpty(&queue))
                printf("\nQueue is Empty.\n");
            else
                printf("\nQueue is not Empty.\n");
            break;
        case 2:
            if (isFull(&queue))
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
                printf("\nEnter element %d:",i+1);
                scanf("%d", &x);
                printf("\nEnter its priority:");
                scanf("%d",&p);
                enqueue(&queue,x,p);
            }
            break;
        case 4:
            printf("\nHow many elements you want to remove from a queue?\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                x = dequeue(&queue);
                printf("\n%d deleted from the queue.\n", x);
            }
            break;
        case 5:
            p=peek(&queue);
            printf("The element with highest priority is %d",p);
            break;
        case 6:
            display(&queue);
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
