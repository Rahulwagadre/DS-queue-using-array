#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 101

// Initialization of Queue
int array[MAX];

// Initialization of rear and front of Queue
int rear=-1,front=-1;

// Checking for overflow
int is_full()
{
    if(front-1 == rear)
    {
        printf("queue if full...!\n\n");
        return 1;
    }
    else{
        printf("queue is not full\n\n");
        return 0;
    }
}

// Checking for underflow
int is_empty()
{
    if(rear == -1 && front == -1)
    {
        printf("queue is empty...!\n\n");
        return 1;
    }
    else{
        printf("queue is not empty...!\n\n");
        return 0;
    }
}

// Enqueue function for insertion
void enqueue(int data)
{
    if(rear == -1 && front == -1)
    {
        rear = (rear + 1)%MAX;
        front = (front + 1)%MAX;
        array[rear] = data;
    }
    else if(front-1 == rear)
    {
        printf("Queue is full. Cant enqueue further...!\n\n");
    }
    else{
        rear = (rear + 1) % MAX;
        array[rear] = data;
    }
}

// Dequeue function for deletion
int dequeue()
{
    if(rear == -1 && front == -1)
    {
        printf("queue is already empty...!\n\n");
        return 0;
    }
    else if(front == rear)
    {
        int res = front;
        front = -1;
        rear = -1;
        return array[res];
    }
    else{
        int res = front;
        front = (front + 1) % MAX;
        return array[res];
    }
}

// get front element
int get_front()
{
    if(rear == -1 && front == -1)
    {
        printf("queue is empty...!");
        return -1;
    }
    else{
        return array[front];
    }
}

// print queue
void show_queue()
{
    int i=0;
    printf("\n\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d ",array[i]);
    }
}

// Main function
int main()
{
    printf("****   Queue implementation using array   ****\n");
    do{
        int choice,data;
        printf("\n\n_______________________________________________________________________________\n\n\n\n");
        printf("-> enqueue : press 1\n-> dequeue : press 2\n-> get front element : press 3\n-> checking for underflow : press 4\n-> checking for overflow : press 5\n-> show queue : press 6\n-> To end programm : press 7\n");
        printf("\n\nenter choice > ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2: printf("\n\nelement deleted > %d",dequeue());
                    break;
            case 3: printf("\n\nfront element > %d",get_front());
                    break;
            case 4: is_empty();
                    break;
            case 5: is_full();
                    break;
            case 6: show_queue();
                    break;
            case 7: printf("\n\nprogram terminated successfully !\n\n");
                    printf("_______________________________________________________________________________\n\n\n");
                    exit(0);
            default: printf("\n\noops...! wrong input");

        }
    }while(1);
    return 0;
}
