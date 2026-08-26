#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *lptr;
    struct Node *rptr;
};
struct Node *L = NULL,*R = NULL;

void insertEnd()
{
    int x;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value:");
    scanf("%d",&x);

    newNode->Info = x;

    if (R == NULL)
    {
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        L = newNode;
        R = newNode;
        return;
    }
    newNode->rptr = NULL;
    newNode->lptr = R;
    R->rptr = newNode;
    R = newNode;
}
void Display()
{
    struct Node *save = L;

    if (L == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    while (save != NULL)
    {
        printf("%d<->",save->Info);
        save = save->rptr;
    }printf("NULL\n");
}

void deleteAlter()
{
    if (L == NULL || L->rptr == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct Node *save = L->rptr,*pred = NULL,*next=NULL;

    while (save != NULL)
    {
        next = save->rptr;
        pred = save->lptr;
        pred->rptr = next;
        next->lptr = pred;
        save = save->rptr->rptr;
    }
    free(save);
}

void main()
{
    int n,x;
    
    printf("Enter total no. of nodes in a list:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        insertEnd();
    }
    Display();
    deleteAlter();
    Display();
}