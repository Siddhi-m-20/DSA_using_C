#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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

void enqueue(int value)
{
    if (isFull())
    {
        printf("\nQueue Overflow.\n");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            queue[rear] = value;
        }
        else
        {
            rear = (rear + 1) % MAX;
            queue[rear] = value;
        }
    }
}

int dequeue()
{
    int x;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        x = queue[front];
        front = (front + 1) % MAX;
    }
    return x;
}

void peek()
{
    int x;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        x = queue[front];
        printf("\nElement at the front is %d\n", x);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        //printf("front index:%d\n",front);
        printf("items:");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d", queue[rear]);
       // printf("\nrear index:%d",rear);
    }
    printf("\n");
}
