#include <stdio.h>
#include <stdlib.h>
#include "dycircular_queue.h"

void main()
{
	int choice, x, n, i;
	while (choice != 5)
	{
		printf("\n*************************Main Menu*********************\n");
		printf("\n=======================================================\n");
		printf("\n1.insert an element\n2.Delete an element\n3.Display The front element.\n4.Display the queue\n5.Exit\n");
		printf("\nEnter your choice ?");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nHow many elements to enter?\n");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("Enter %d element in queue.", i + 1);
				scanf("%d", &x);
				enqueue(x);
			}
			break;
		case 2:
			dequeue();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nEnter valid choice??\n");
			break;
		}
	}
}
