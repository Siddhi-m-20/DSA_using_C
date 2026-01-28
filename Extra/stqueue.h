#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue[MAX];
int front=-1,rear=-1;

int isEmpty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int value){
    if(isFull()){
        printf("\nQueue Overflow.\n");
    }
    else{
        if(isEmpty()){
            front=0;
            rear=0;
            queue[front]=value;
        }
        else{
            rear++;
            queue[rear]=value;
        }
    }
}

int dequeue(){
    int x=queue[front];
    if(isEmpty()){
        printf("\nQueue Underflow\n");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return x;
}

int peek(int x){
    int i;
    if(isEmpty()){
        printf("\nQueue Underflow\n");
    }
    else{
        // x=queue[front];
        // printf("\nElement at the front is %d\n",x);
        for(i=front;i<=rear;i++){
            if (x==queue[i])
            {
             return i+1;
            }
            
        }
    }
    return 0;
}

void display(){
    int i;
     if(isEmpty()){
        printf("\nQueue Underflow\n");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}