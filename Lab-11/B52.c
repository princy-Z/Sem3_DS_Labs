#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *first = NULL,*last = NULL;

void insertlast(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = x;

    if (first == NULL)
    {
       newNode->Link = newNode;
       first = newNode;
       last = newNode;
    }
    else{
        newNode->Link = first;
        last->Link = newNode;
        last = newNode;
    }
}

struct Node *h1=NULL , *h2=NULL;
void split()
{
    struct Node *slow = first,*fast = first;
    while (fast->Link != first && fast->Link->Link != first)
    {
        slow = slow->Link;
        fast = fast->Link->Link;
    }
    
    h2 = slow->Link;

    h1 = first;
    slow->Link = h1;
    
    if (fast->Link->Link == first)
    {
        fast = fast->Link;
    }
    fast->Link = h2;
}

void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    struct Node *save = first;

    do
    {
        printf("%d->",save->Info);
        save = save->Link;
    }while (save != first);
    printf("\n");
    //printf("%d\n",save->Info);
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
    split();
    display(h1);
    display(h2);
}