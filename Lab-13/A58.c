#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *top = NULL;

void push(int x)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));

    new->Info = x;
    new->Link = top;
    top = new;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    struct Node *save = top;
    top = top->Link;

    int val = save->Info;

    free(save);
    return val;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    return top->Info;
}

int peep(int i)
{
    if (top == NULL)
    {
        printf("Stack is empty...\n");
    }
    int count = 1;
    struct Node *save = top;

    while (save != NULL && count < i)
    {
        save = save->Link;
        count++;
    }
    
    return save->Info;
}

void change(int i,int newX)
{
    if (top == NULL)
    {
        printf("Stack is empty...\n");
    }
    int count = 1;
    struct Node *save = top;

    while (save != NULL && count < i)
    {
        save = save->Link;
        count++;
    }
    save->Info = newX;
}

void Display()
{
    if (top == NULL)
    {
        printf("Stack is empty...\n");
        return;
    }
    struct Node *save = top;

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
    int x,choice;

    do
    {
        printf("1.push an element\n2.pop an element\n3.Display Queue\n4.peep\n5.change\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter an element:");
            scanf("%d",&x);
            push(x);
            break;

        case 2:
            pop();
            printf("\n");
            break;

        case 3:
            display();
            break;
        
        case 4:
            peep(2);
            break;

        case 5:
            printf("Enter new element to change:");
            scanf("%d",&x);
            change(2,x);
            break;

        default:
            printf("Invalid choice!");
            break;
        }
    }while (choice < 6);
}