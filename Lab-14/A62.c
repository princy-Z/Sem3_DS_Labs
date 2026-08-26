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

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    struct Node *save = top;
    top = top->Link;

    free(save);
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
        printf("%c ->",save->Info);
        save = save->Link;
    }
    printf("NULL\n");
}
void checkString(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '*')
        {
            pop();
        }else{
           push(str[i]);
        }
       i++;
    }
    Display();
}

void main()
{
    char str[10];
        
    printf("Enter a string:");
    scanf("%s",str);

    checkString(str);
}