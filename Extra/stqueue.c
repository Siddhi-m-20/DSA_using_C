#include <stdio.h>
#include <stdlib.h>
#include "stqueue.h"

void main()
{
    int t, s, x, j;
    t = isEmpty();
    if (t == 1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nQueue is not Empty\n");
    }
    enqueue(1);
    enqueue(20);
    enqueue(18);
    enqueue(36);
    enqueue(13);
    display();
    s = isFull();
    if (s == 1)
    {
        printf("\nQueue is FULL\n");
    }
    else
    {
        printf("\nQueue is not full\n");
    }
    j = peek(13);
    if (j == 0)
    {
        printf("\nElement not found in Queue\n");
    }
    else
    {
        printf("\nElement found at %d loc in q\n", j);
    }
    x = dequeue();
    printf("\n%d is deleted from the queue.\n", x);
    display();
}