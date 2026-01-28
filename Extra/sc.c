#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            queue[front] = x;
        }
        else
        {
            rear = (rear + 1) % MAX;
            queue[rear] = x;
        }
    }
}

int dequeue()
{
    int x;
    if (isEmpty())
    {
        printf("\nQueue Underflow");
        return -1;
    }
    else
    {
        if (front == rear)
        {
            x = queue[front];
            front = -1;
            rear = -1;
        }
        else
        {
            x = queue[front];
            front = (front + 1) % MAX;
        }
    }
    return x;
}

int peek(int x)
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue Underflow");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            if (queue[i] == x)
            {
                return i + 1;
            }
        }
    }
    return 0;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue Underflow");
    }
    else
    {
        for (i = front; i <= rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, i, x, n;
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
            printf("\nEnter Element to peek:\n");
            scanf("%d", &x);
            n = peek(x);
            if (n == 0)
                printf("\n No element found in the Queue");
            else
                printf("\nElement found at %d location.\n", n);
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