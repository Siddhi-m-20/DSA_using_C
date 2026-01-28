#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front;
struct node *rear;

int isempty();
int peek();
void enqueue();
int dequeue();
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

void enqueue()
{
	struct node *ptr;
	int item;

	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		printf("\nEnter Value?\n");
		scanf("%d", &item);
		ptr->data = item;
		if (isempty())
		{
			front = ptr;
			rear = ptr;
			front->next = NULL;
			rear->next = NULL;
		}
		else
		{
			rear->next = ptr;
			rear = ptr;
			rear->next = NULL;
		}
	}
}

int dequeue()
{
	struct node *ptr;
	int x;
	if (isempty())
	{
		printf("\n Queue is Empty cannot be dequeued.\n");
		return -1;
	}
	else
	{
		x = front->data;
		ptr = front;
		front = front->next;
		free(ptr);
	}
	return x;
}

int peek()
{
	int x;
	if (isempty())
	{
		printf("\n Queue is Empty.\n");
		return -1;
	}
	else
	{
		x = front->data;
	}
	return x;
}

void display()
{
	struct node *ptr;
	ptr = front;
	if (isempty())
	{
		printf("\n Queue is Empty.\n");
	}
	else
	{
		printf("\nPrinting Values...\n");
		while (ptr != NULL)
		{
			printf("\n%d", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
