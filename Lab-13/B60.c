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

char pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    struct Node *save = top;
    top = top->Link;

    char val = save->Info;

    free(save);
    return val;
}

int checkString(char *str)
{
    int i = 0;

    if (str[0] != 'a')
    {
        printf("Invalid(a)!\n");
        return 0;
    }
    while (str[i] == 'a')
    {
        push(str[i]);
        i++;
    }
    if (str[i] != 'b')
    {
        printf("Invalid(b)!\n");
        return 0;
    }
    
    while (str[i] == 'b')
    {
        if (top == NULL)
        {
            printf("New stack is empty!\n");
            return 0;
        }
        pop();
        i++;
    }
    if (str[i] != '\0')
    {
        printf("String have other character!\n");
        return 0;
    }
    
    if (top == NULL)
    {
        return 1;
    }else{
        printf("Invalid2\n");
        return 0;
    }
}

void main()
{
    char str[20];
    int T;

    printf("Enter no. of test cases:");
    scanf("%d",&T);

    for (int i = 1; i <= T; i++)
    {
        printf("Enter string:");
        scanf("%s",str);

        int output = checkString(str);

        if (output == 1)
        {
            printf("Valid\n");
        }else{
            printf("Invalid!\n");
        }
    }
}