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

int count()
{
    int count = 0;
    struct Node *save = first;

    while (save != NULL)
    {
        count++;
        save = save->Link;
    }
    return count;
}
void swap(int x)
{
    int n = count(),temp;
    struct Node *node1,*node2,*save;
    
    save = first;

    if (x > n || x <= 0)
    {
        printf("Position is out of the list...!\n");
        return;
    }
    
    for (int i = 1; i < x; i++)
    {
        save = save->Link;
    }
    node1 = save;

    save = first;

    for (int i = 1; i < n - x + 1; i++)
    {
        save = save->Link;
    }
    node2 = save;

    temp = node1->Info;
    node1->Info = node2->Info;
    node2->Info = temp;
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
    int n,k,x;
    
    printf("Enter total no. of nodes in a list:");
    scanf("%d",&n);

    printf("Enter a position to swap two values:");
    scanf("%d",&k);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter a node:");
        scanf("%d",&x);
        insertlast(x);
    }
    swap(k);
    display();
}