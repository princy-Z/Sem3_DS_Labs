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
        return '\0';
    }
    struct Node *save = top;
    top = top->Link;

    char val = save->Info;

    free(save);
    return val;
}
int F(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 9;
    else if(x == ')' || x == '\0')
        return 0;
    else
        return 7;
}

int G(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return 8;
}

int R(char x)
{
    if (x != '(' && x != ')')
    {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        {
            return -1;
        }else{
            return 1;
        }
    }
    return 0;
}
void checkString(char str[])
{
    int i = 0;
    int j = 0;
    char temp;
    char polish[50] = "";
    int rank = 0;

    push('(');
    
    while (1)
    {
        if (top == NULL)
        {
            printf("Stack is empty...\n");
            return;
        }
        
        while (G(top->Info) > F(str[i]))
        {
            temp = pop();
            polish[j++] = temp;
            rank += R(temp);
            if (rank < 1)
            {
                printf("InvalidR!\n");
                return;
            }

        }
        if (G(top->Info) != F(str[i]))
        {
            push(str[i]);
        }else{
            pop();
        }

        if (str[i] == '\0')
        {
            break;
        }
        i++;
    }
   
    polish[j] = '\0';

    if (top != NULL || rank != 1)
    {
        printf("InvalidLast!\n");
    }else{
        printf("%s",polish);
        printf("\n");
    }
}

void main()
{
    char str[20];
    printf("Enter string:");
    scanf("%s",str);

    checkString(str);
}