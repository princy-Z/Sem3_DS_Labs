#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Info;
    struct Node *Link;
};

struct Node *first = NULL;

void insertlast(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = x;
    newNode->Link = NULL;
    if (first == NULL)
    {
        first = newNode;
        printf("Value insert at first position.\n");
        return;
    }
    struct Node *save = first;

    while(save->Link != NULL)
    {
        save = save->Link;
    }
    save->Link = newNode;
    
    printf("Value inserted successfully.\n"); 
}

void reverse()
{
    struct Node *save = first,*next = NULL,*pred = NULL;

    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    
    while (save != NULL)
    {
        next = save->Link;
        save->Link = pred;
        pred = save;
        save = next;
    }
    first = pred;
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct Node *save = first;

    printf("Linked List:");
    while (save != NULL)
    {
        printf("%d ->",save->Info);
        save = save->Link;
    }
    printf("NULL\n");
}

void main()
{
    int n,x;
    
    printf("Enter total no. of nodes in a list:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter a node:");
        scanf("%d",&x);
        insertlast(x);
    }
    reverse();
    display();
}