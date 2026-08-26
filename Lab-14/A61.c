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

int checkString(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            pop();
        }
        else if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
            push(str[i]);
            pop();
        }
        i++;
    }
    if (top == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

void main()
{
    char str[10];
    int T;

    printf("Enter no. of test cases:");
    scanf("%d",&T);
    for (int i = 1; i <= T; i++)
    {
        printf("Enter a string:");
        scanf("%s",str);

        int output = checkString(str);

        if (output == 1)
        {
            printf("1\n");
        }else{
            printf("0\n");
        }
    } 
}