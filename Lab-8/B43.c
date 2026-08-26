#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Info;
    struct Node *Link;
};
struct Node *first1 = NULL;
struct Node *first2 = NULL;

void insertlast1(int x)
{   
    struct Node *Node1 = (struct Node *)malloc(sizeof(struct Node));

    Node1->Info = x;
    Node1->Link = NULL;
    if (first1 == NULL)
    {
        first1 = Node1;
        return;
    }
    struct Node *save1 = first1;

    while(save1->Link != NULL)
    {
        save1 = save1->Link;
    }
    save1->Link = Node1;

}

void insertlast2(int x)
{ 
    struct Node *Node2 = (struct Node *)malloc(sizeof(struct Node));

    Node2->Info = x;
    Node2->Link = NULL;
    if (first2 == NULL)
    {
        first2 = Node2;
        return;
    }
    struct Node *save2 = first2;

    while(save2->Link != NULL)
    {
        save2 = save2->Link;
    }
    save2->Link = Node2;

}

// void display()
// {
//     printf("Node:-\n");

//     if (first1 == NULL)
//     {
//         printf("List is empty...\n");
//         return;
//     }
//     struct Node *save1 = first1;

//     printf("Linked List:");
//     while (save1 != NULL)
//     {
//         printf("%d ->",save1->Info);
//         save1 = save1->Link;
//     }
//     printf("NULL\n");
// }

int Check()
{
    struct Node *save1 = first1;
    struct Node *save2 = first2;
    while (save1->Link != NULL || save2->Link != NULL)
    {
        if(save1->Info != save2->Info)
        {
            return 0;
        }
        save1 = save1->Link;
        save2 = save2->Link;
    }
    return 1;
}
void main()
{
    int n,x1,x2;
    
    printf("Enter total no. of nodes in a list:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter a value of list-1:");
        scanf("%d",&x1);

        printf("Enter a value of list-2:");
        scanf("%d",&x2);

        insertlast1(x1);
        insertlast2(x2);
    }
    printf("\n");
   
    if (Check())
    {
        display();
        printf("Both Node are same...\n");
    }
    else{
        printf("Both Node are not same...\n");
    }
}