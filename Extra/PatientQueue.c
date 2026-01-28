#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50

typedef struct
{
    int data;
    int priority;
} queue_element;

typedef struct
{
    queue_element elements[MAX_SIZE];
    int front;
    int rear;
} priority_queue;

void initializeQueue(priority_queue *queue);
int isEmpty(priority_queue *queue);
int isFull(priority_queue *queue);
void enqueue(priority_queue *queue, int data, int priority);
int dequeue(priority_queue *queue);
int peek(priority_queue *queue);
void display(priority_queue *queue);

void initializeQueue(priority_queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(priority_queue *queue)
{
    return (queue->front == -1);
}

int isFull(priority_queue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(priority_queue *queue, int data, int priority)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
        queue->elements[queue->front].data = data;
        queue->elements[queue->front].priority = priority;
    }
    else
    {
        int i = queue->rear;
        while (i >= 0 && priority < queue->elements[i].priority)
        {
            queue->elements[(i + 1) % MAX_SIZE] = queue->elements[i];
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        }
        queue->elements[(i + 1) % MAX_SIZE].data = data;
        queue->elements[(i + 1) % MAX_SIZE].priority = priority;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
}
int dequeue(priority_queue *queue)
{
    int x;
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else
    {
        x = queue->elements[queue->front].data;
        if (queue->front == queue->rear)
        {
            initializeQueue(queue);
        }
        else
        {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
    return x;
}
void display(priority_queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    do
    {
        printf("%d (Priority: %d) ", queue->elements[i].data, queue->elements[i].priority);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

void main()
{

    priority_queue queue;
    initializeQueue(&queue);
    int choice, n;
    int i, x,p;
    printf("\n*****************Patient Management using ascending priority queue in static implementation.***********************\n");
    while (choice != 7)
    {
        printf("\n1.Enter patient into a queue\n2.Delete Patient from queue\n3.Display all patient\n4.Exit.\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nHow many patients?\n");
            scanf("%d", &n);
            printf("\nEnter %d patients.\n", n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter patient %d:",i+1);
                scanf("%d", &x);
                printf("\nEnter its priority:");
                scanf("%d",&p);
                enqueue(&queue,x,p);
            }
            break;
	case 2:
            printf("\nHow many patients you want to remove from a queue?\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                x = dequeue(&queue);
                printf("\n%d deleted from the queue.\n", x);
            }
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter corrct choice.\n");
            break;
        }
    }
}

