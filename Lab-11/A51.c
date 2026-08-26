#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *first = NULL,*last = NULL;

void insertfirst(int x)
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
        first = newNode;
    }
}
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

void deleteByPos()
{
    struct Node *save,*pred;
    int pos;

    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    printf("Enter position to delete that node: ");
    scanf("%d",&pos);

    if (pos == 1)
    {
        save = first;
        if (first == last)
        {
            first = NULL;
            last = NULL;
        }else{
            first = first->Link;
            last->Link = first;
        }
    }
    
    save = first;

    for (int i = 1; i < pos; i++)
    {
        pred = save;
        save = save->Link;
    }
    if (save == first)
    {
        printf("Position not match!");
        return;
    }
    pred->Link = save->Link;

    if (save == last)
    {
        last = pred;
    }
    free(save);
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    struct Node *save = first;

    // while (save != last)
    // {
    //     printf("%d->",save->Info);
    //     save = save->Link;
    // }
    //printf("%d\n",save->Info);

    do{
        printf("%d->",save->Info);
        save = save->Link;
    }while(save != first);
    printf("\n");
}

void main()
{
    int choice;
    int a;

    do
    {
        printf("::MENU::\n");
        printf("1.Insert at First\n2.Delete node from specific position\n3.Insert at Last\n4.Display\n5.Exit\n");
        printf("Enter a choice from given options:");
        scanf("%d",&choice);
        printf("\n");
        
        switch (choice)
        {
            case 1:
                printf("Enter a value of node:");
                scanf("%d",&a);
                printf("\n");
                insertfirst(a);
                break;
        
            case 2:
                deleteByPos();
                break;

            case 3:
                printf("Enter a value of node:");
                scanf("%d",&a);
                printf("\n");
                insertlast(a);
                break;

            case 4:
                display();
                break;

            default:
                printf("Invalid Choice!");
                break;
        }
    }while (choice < 5);
}