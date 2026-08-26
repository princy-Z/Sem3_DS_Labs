#include<stdio.h>
#include<stdlib.h>

#define size 5

int Queue[size];
int front = -1;
int rear = -1;

void EnqueueAtFront(int n)
{
    if (front == 0)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }else{
        front--;
    }
    Queue[front] = n;
}

void EnqueueAtRear(int n)
{
    if (rear == size-1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }else{
        rear++;
    }
    Queue[rear] = n;
}

int DequeueFromFront()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int y = Queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }else{
        front++;
    }
    return y;   
}

int DequeueFromRear()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return -1;
    }

    int y = Queue[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }else{
        rear--;
    }
    return y; 
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    while (i <= rear) {
        printf("%d ", Queue[i]);
        i++;
    }
    printf("\n");
}

void main()
{
    int choice,n;

    do
    {
        printf("\n");
        printf("1.Enqueue an element at Front\n2.Enqueue an element at Rear\n3.Dequeue an element from Front\n4.Dequeue an element from End\n5.Display Queue\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter an element insert at Front:");
            scanf("%d",&n);
            EnqueueAtFront(n);
            break;

        case 2:
            printf("Enter an element to insert at Rear:");
            scanf("%d",&n);
            EnqueueAtRear(n);
            break;

        case 3:
            DequeueFromFront();
            printf("\n");
            break;

        case 4:
            DequeueFromRear();
            break;
        
        case 5:
            display();
            break;

        default:
            printf("Invalid choice!");
            break;
        }
    }while (choice < 6);
}