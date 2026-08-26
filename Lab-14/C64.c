#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *Link;
};
struct Node *top = NULL;

void push(char x)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));

    new->Info = x;
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
void Display()
{
    if (top == NULL)
    {
        printf("Stack is empty...\n");
        return;
    }
    struct Node *save = top;

    printf("Stack:");
    while (save != NULL)
    {
        printf("%c ",save->Info);
        save = save->Link;
    }
    printf("\n");
}
void checkString(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
        {
            reverse();
            push(str[i]);
        }else{
            push(str[i]);
        }
        i++;
    }
    reverse();
    Display();
}

void main()
{
    int T,S;

    printf("Enter no. of testcases:");
    scanf("%d",&T);

    for (int i = 1; i <= T; i++)
    {
        printf("Enter size of string:");
        scanf("%d",&S);

        char str[S];
        
        printf("Enter a string:");
        scanf("%s",str);

        checkString(str);
    }
}