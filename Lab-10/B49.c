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

int GCD(int a,int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }else{
            b = b - a;
        }
    }
    return a;
}

void insertGCD()
{
    struct Node *newNode,*save = first;

    while (save != NULL && save->Link != NULL)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        int gcd = GCD(save->Info , save->Link->Info);

        newNode->Info = gcd;
        newNode->Link = save->Link;
        save->Link = newNode;

        save = newNode->Link;
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
    insertGCD();
    display();
}