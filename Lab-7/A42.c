// 42. Write a menu driven program to implement following operations on the singly 
// linked list.  
// -> Insert a node at the front of the linked list. 
// -> Display all nodes. 
// -> Delete a first node of the linked list. 
// -> Insert a node at the end of the linked list. 
// -> Delete a last node of the linked list. 
// -> Delete a node from specified position. 
// -> Count the no. of nodes in the linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *first = NULL;

void insertfirst(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = x;
    newNode->Link = first;
    first = newNode;
    printf("Value insert at first position.\n");
}

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

void deletefirst()
{
    struct Node *save;
    
    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    save = first;
    first = first->Link;

    free(save);
    printf("First Node Deleted!");
}

void deleteEnd()
{
    struct Node *save,*pred;
    
    if (first == NULL)
    {
        printf("List is empty...\n");
        return;
    }  
    save = first;

    while (save->Link != NULL)
    {
        pred = save;
        save = save->Link;
    }
    pred->Link = save->Link;
    free(save);

    printf("Last Node Deleted!\n");
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
        deletefirst();
        return;
    }
    
    save = first;

    for (int i = 1; i < pos && save != NULL; i++)
    {
        pred = save;
        save = save->Link;
    }
    
    if (save == NULL)
    {
        printf("Position not match!");
        return;
    }
    
    pred->Link = save->Link;
    free(save);

    printf("Node Deleted!");
}

void count()
{
    int count = 0;
    struct Node *save = first;

    while (save != NULL)
    {
        count++;
        save = save->Link;
    }
    
    printf("No. of Nodes : %d\n",count);
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
    int choice;
    int a;

    do
    {
        printf("::MENU::\n");
        printf("1.Insert at First\n2.Display\n3.Delete First\n4.Insert at Last\n5.Delete Last\n");
        printf("6.Delete node from specific position\n7.Count Total Nodes\n8.Exit\n");
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
                display();
                break;

            case 3:
                deletefirst();
                break;

            case 4:
                printf("Enter a value of node:");
                scanf("%d",&a);
                printf("\n");
                insertlast(a);
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deleteByPos();
                break;
        
            case 7:
                count();
                break;

            default:
                printf("Invalid Choice!");
                break;
        }
    }while (choice < 8);
}