#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *lptr;
    struct Node *rptr;
};
struct Node *L = NULL,*R = NULL;

void insertFirst()
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
    newNode->lptr = NULL;
    newNode->rptr = L;
    L->lptr = newNode;
    L = newNode;
}
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
int countNode()
{
    int count = 0;
    struct Node *save = L;

    if (L == NULL)
    {
        printf("List is Empty!\n");
        return 0;
    }
    
    while (save != NULL)
    {
        count++;
        save = save->rptr;
    }
    return count;
}
void deletebypos()
{
    int pos, n = countNode();
    struct Node *old = L;
    printf("Enter Position to delete:");
    scanf("%d",&pos);

    for (int i = 1; i < pos; i++)
    {
        old = old->rptr;
    }
    
    if (L == R)
    {
        L = NULL;
        R = NULL;
        return;
    }else if (old == L)
    {
        L = L->rptr;
        L->lptr = NULL;
    }else if (old == R)
    {
        R = R->lptr;
        R->rptr = NULL;
    }else{
        old->lptr->rptr = old->rptr;
        old->rptr->lptr = old->lptr;
    }
    free(old);
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
    }
    printf("NULL\n");
}
void main()
{
    int x,choice;

    do
    {
        printf("1.Insert at first\n2.Delete from specific position\n3.Insert at last\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            insertFirst(L);
            break;
        
        case 2:
            deletebypos();
            break;
        case 3:
            insertEnd();
            break;

        case 4:
            Display();
            break;

        default:
            printf("Invalid Choice!");
            break;
        }
    } while (choice < 5);
    
}