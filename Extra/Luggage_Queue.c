#include <stdio.h>
#include <stdlib.h>
#include "stqueue.h"

int main()
{
    int n, i;
    printf("Enter how many luggages are there in queue?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        enqueue(i+1);
    }
    for (i = 0; i < n; i++)
    {
        printf("\nLuggeges in queue:");
        display();
        printf("\nLuggege at the Luggage checking machine:%d", dequeue());
    }
    return 0;
}
