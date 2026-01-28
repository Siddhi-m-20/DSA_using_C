#include <stdio.h>
#include <stdlib.h>
#include "stqueue.h"

int main()
{
    int n, i, x;
    printf("Enter how many vehicles can be in queue?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter vehicle number of %d:", i+1);
        scanf("%d", &x);
        enqueue(x);
    }
    for (i = 0; i < n; i++)
    {
        printf("\nVehicles in queue:");
        display();
        printf("\nVehicle at the tollbooth:%d", dequeue());
    }
    return 0;
}
