#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node * first = NULL, *begin = NULL;

void insertlast(int x)
{
    struct Node *Node1 = (struct Node *)malloc(sizeof(struct Node));

    Node1->Info = x;
    Node1->Link = NULL;
    if (first == NULL)
    {
        first = Node1;
        printf("Value insert at first position.\n");
        return;
    }
    struct Node *save = first;

    while(save->Link != NULL)
    {
        save = save->Link;
    }
    save->Link = Node1;
    
    printf("Value inserted successfully.\n"); 
}

void copy()
{
    if (first == NULL)
    {
        printf("List is empty...\n");\
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    //first node copying
    newNode->Info = first->Info;
    begin = newNode;
    struct Node *save = first,*pred=NULL;

    while (save->Link != NULL)
    {
        pred = newNode;
        save = save->Link;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->Info = save->Info;
        pred->Link = newNode;
    }
    newNode->Link = NULL; 
}

void display()
{
    if (begin == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct Node *pred = begin;

    printf("Linked List:");
    while (pred != NULL)
    {
        printf("%d ->",pred->Info);
        pred = pred->Link;
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
    copy();
    display();
}