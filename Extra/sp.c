#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct
{
    int data[MAX_SIZE];
    int priority[MAX_SIZE];
    int front, rear;
} PriorityQueue;

void initializeQueue(PriorityQueue *q);
int isEmpty(PriorityQueue *q);
int isFull(PriorityQueue *q);
void enqueue(PriorityQueue *q, int element, int priority);
int dequeue(PriorityQueue *q);
int peek(PriorityQueue *q);
void displayQueue(PriorityQueue *q);

void initializeQueue(PriorityQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(PriorityQueue *q)
{
    return (q->front == -1);
}

int isFull(PriorityQueue *q)
{
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(PriorityQueue *q, int element, int priority)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    int i;
    for (i = q->rear; i >= 0 && q->priority[i] >= priority; i--)
    {
        q->data[i + 1] = q->data[i];
        q->priority[i + 1] = q->priority[i];
    }
    q->data[i + 1] = element;
    q->priority[i + 1] = priority;

    if (q->front == -1)
        q->front = 0;
    q->rear++;
}

int dequeue(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int element = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return element;
}

int peek(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    return q->data[q->front];
}

void displayQueue(PriorityQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main()
{
    PriorityQueue q;
    initializeQueue(&q);

    enqueue(&q, 10, 2);
    enqueue(&q, 20, 1);
    enqueue(&q, 30, 3);

    displayQueue(&q);

    printf("Peek: %d\n", peek(&q));

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printf("Is Empty: %d\n", isEmpty(&q));

    displayQueue(&q);

    return 0;
}
