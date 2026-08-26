#include<stdio.h>

#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = x;
    newNode->Link = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        printf("Value insert at first position.\n");
        return;
    }

    struct Node *save = front;

    while(save->Link != NULL)
    {
        save = save->Link;
    }

    save->Link = newNode;
    rear = newNode;
}

int Dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
    }
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        printf("Now Queue becomes empty!\n");
    }else{
        struct Node *save = front;
        front = front->Link;

        int val = save->Info;
    

        free(save);
        return val;
    }
    return 0;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty...\n");
        return;
    }
    struct Node *save = front;

    printf("Stack:");
    while (save != NULL)
    {
        printf("%d ->",save->Info);
        save = save->Link;
    }
    printf("NULL\n");
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
