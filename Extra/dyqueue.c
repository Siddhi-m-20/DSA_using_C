#include<stdio.h>
#include<stdlib.h>
#include"dyqueue.h"

void main ()
{
int choice,x;
while(choice != 5){
	printf("\n*************************Main Menu*********************\n");
	printf("\n=======================================================\n");
	printf("\n1.insert an element\n2.Delete an element\n3.Display The front element.\n4.Display the queue\n5.Exit\n");
	printf("\nEnter your choice ?");
	scanf("%d",& choice);
	switch(choice)
	{
	case 1:
		enqueue();
		break;
	case 2:
		x=dequeue();
		printf("%d deleted from the queue\n",x);	
		break;
	case 3:
		x=peek();
		printf("%d is the front element.\n",x);
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
