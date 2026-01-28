#include<stdio.h>
#define MAX 5

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

int isfull(stack* p)
{
    if(p->top==MAX-1)
        return 1;  //stack is full
    else
        return 0;
}

int isempty(stack* p)
{
    if(p->top == -1)
        return 1;  //stack is empty
    else
        return 0;
}


void init(stack* p)
{
    p->top = -1;
}

void push(stack* p,int x)
{   //increment TOP and then insert
    int ans;
    ans = isfull(p);
    if(ans==1)
        printf("\nSTACK IS FULL\n");
    else
        {
            p->top++;
            p->data[p->top] = x;
        }
}

int pop(stack* p)
{   //delete and then decrement top
    int x=-1; // any dummy no which is not going to be inserted
    int ans;

    ans = isempty(p);

    if(ans==1)
        printf("\nSTACK IS EMPTY");
    else
        {
            x = p->data[p->top];
            p->top--;
        }    
    
    return x;
}

void display(stack* p)
{
    int i;
    for(i=p->top;i>=0;i--)
        printf("%d\n",p->data[i]);
}

int peek(stack* p)
{
    int ans;
    ans = isempty(p);
    if(ans==1)
        {
            printf("\nStack is empty");
            return -1; // return dummy element
        }
    else
        return p->data[p->top];
}


