#include<stdio.h>
#include<stdlib.h>

int Queue[5];
int front = -1;
int rear = -1;

int Enqueue(int n)
{
    if (rear > 4)
    {
        printf("Queue Overflow.\n");
    }
    Queue[++rear] = n;

    if (front == -1)
    {
        front = 0;
    }  
}

int Dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int y = Queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }else{
        front++;
    }
    return y;   
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d",Queue[i]);
    }
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