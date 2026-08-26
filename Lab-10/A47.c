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

void sort()
{
    if (first==NULL)
    {
        printf("List id empty...\n");
        return;
    }
    struct Node *save = first,*next;
    int temp;
    while(save->Link != NULL)
    { 
        next = save->Link;
        while (next != NULL)
        {
            if (save->Info > next->Info)
            {                  
                temp = save->Info;
                save->Info = next->Info;
                next->Info = temp;
            }
            next = next->Link;
        }
        save = save->Link;
    }
}

// void sort()
// {
//     if (first==NULL)
//     {
//         printf("List id empty...\n");
//         return;
//     }
    
//     struct Node *save = first , *next = save->Link , *pred=NULL;
//     while (save->Link != NULL)
//     {
//         while (save->Link != NULL)
//         {
//             if (save->Info > next->Info)
//             {
//                 next = save->Link;
//                 save->Link = pred;
//                 save->Link = next->Link;
//                 next->Link = save;
//                 pred->Link = next;
//                 pred = next;
//             }else{
//                 pred = save;
//                 save = save->Link;
//             }
//         }
//         save = save->Link;
//     }
// }

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
    sort();
    display();
}