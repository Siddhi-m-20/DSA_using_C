#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

int isempty();
void peek();
void enqueue();
void dequeue();
void display();

int isempty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        newnode->data = x;
        newnode->next = NULL;
        if (isempty())
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (isempty())
    {
        printf("\nQueue is empty");
    }
    else
    {

        int x = front->data;
        if (front == rear)
        {
            front = rear = NULL;
            free(temp);
        }
        else
        {
            front = front->next;
            rear->next = front;
            free(temp);
        }
        printf("%d deleted from the queue\n", x);
    }
}
void peek()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe front element is %d", front->data);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
    }
    else
    {

        printf("\n The elements in a Queue are : ");
        while (temp->next != front)
        {
            printf("%d,", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
