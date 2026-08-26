#include<stdio.h>
#include<stdlib.h>

struct  Node
{
    int Info;
    int prio;
    struct Node *Link;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x,int p)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = x;
    newNode->prio = p;
    newNode->Link = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        printf("Value insert at first position.\n");
        return;
    }

    struct Node *save = front,*pred = NULL;

    while(save->Link != NULL && p >= save->prio)
    {
        pred = save;
        save = save->Link;
    }

    if (save == rear)
    {
        save->Link = newNode;
        rear = newNode;
    }else{
        pred->Link = newNode;
        newNode->Link = save;
    }
}

int Dequeue(int p)
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

        struct Node *save = front,*pred = NULL;

        if (p == 1)
        {
            front = front->Link;
            int val = save->Info;
            return val; 
        }
        while(save->Link != NULL && p > save->prio)
        {
            pred = save;
            save = save->Link;
        }
        int val = save->Info;

        pred->Link = save->Link;
        save = save->Link;

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
    int choice,x,p,temp;

    do
    {
        printf("\n");
        printf("1.Enqueue an element\n2.Dequeue an element\n3.display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter value:");
                scanf("%d",&x);
                printf("Enter priority:");
                scanf("%d",&p);
                Enqueue(x,p);
                break;
            
            case 2:
                printf("Enter priority to delete:");
                scanf("%d",&p);
                temp = Dequeue(p);
                printf("Dequeued element:%d\n",temp);
                break;

            case 3:
                display();

            default:
                printf("Invalid Choice!");
                break;
        }
    } while (choice < 4);
    
}
