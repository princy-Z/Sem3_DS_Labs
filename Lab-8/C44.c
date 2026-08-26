#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
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
        return;
    }
    struct Node *save = first;

    while(save->Link != NULL)
    {
        save = save->Link;
    }
    save->Link = newNode;
}

void duplicate()
{
    struct Node *save = first;
    struct Node *dup;

    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    while (save->Link != NULL)
    {
        if (save->Info == save->Link->Info)
        {
            dup = save->Link;
            save->Link = save->Link->Link;
            free(dup);
        }else{
            save = save->Link;
        } 
    }
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
    duplicate();
    display();
}