#include<stdio.h>
#include<stdlib.h>

#define size 5

int Queue[size];
int front = -1;
int rear = -1;

void Enqueue(int n)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue Overflow.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }  
    rear = (rear + 1) % size;
    Queue[rear] = n; 
}

int Dequeue()
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
        front = (front + 1) % size;
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
    while (1) {
        printf("%d ", Queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % size;
    }
    printf("\n");
}

void main()
{
    int choice,n;

    do
    {
        printf("\n");
        printf("1.Enqueue an element\n2.Dequeue an element\n3.Display Queue\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter an element:");
            scanf("%d",&n);
            Enqueue(n);
            break;

        case 2:
            Dequeue();
            printf("\n");
            break;

        case 3:
            display();
            break;
        
        default:
            printf("Invalid choice!");
            break;
        }
    }while (choice < 4);
}