#include<stdio.h>
#include<stdlib.h>

struct Node
{   int start;
    int end;
    struct Node *Link;
};
struct Node *top = NULL;

void push(int s,int e)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));

    new->start = s;
    new->end = e;
    new->Link = top;
    top = new;
}

void reverse()
{
    struct Node *save = top,*next = NULL,*pred = NULL;

    if (top == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    
    while (save != NULL)
    {
        next = save->Link;
        save->Link = pred;
        pred = save;
        save = next;
    }
    top = pred;
}

int compare(const void *a,const void *b)
{
    struct Node *node1 = (struct Node *)a;
    struct Node *node2 = (struct Node *)b;

    return (node1->start - node2->start);
}

void merge(struct Node arr[],int n)
{
    if(n <= 0) return;

    qsort(arr,n,sizeof(struct Node),compare);

    push(arr[0].start,arr[0].end);

    for (int i = 1; i < n; i++)
    {
        int temp = top->end;
        if (arr[i].start <= temp)
        {
           if (arr[i].end > temp)
           {
            top->end = arr[i].end;
           }
        }else{
            push(arr[i].start,arr[i].end);
        }
    }
}
void display()
{
    if (top == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct Node *save = top;

    printf("Linked List:");
    while (save != NULL)
    {
        printf("{%d , %d}->",save->start,save->end);
        save = save->Link;
    }
    printf("NULL\n");
}

void main()
{
    int n;

    printf("Enter no. of nodes:");
    scanf("%d",&n);

    struct Node arr[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter start:");
        scanf("%d",&arr[i].start);
        printf("Enter end:");
        scanf("%d",&arr[i].end);
        //push(arr[i].start,arr[i].end);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    merge(arr,size);
    reverse();
    display();
}