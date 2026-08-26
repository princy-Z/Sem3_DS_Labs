#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

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
int calc(float a,float b,char op)
{
    int result;

    switch (op)
    {
    case '+':
        result = a + b;
        break;
    
    case '-':
        result = a - b;
        break;
    
    case '*':
        result = a * b;
        break;

    case '/':

        if (b == 0)
        {
            printf("Not devisible by zero!\n");
        }
        result = a / b;
        break;

    case '^':
        result = ceil(pow(b,a));
        break;
    default:
        printf("Invalid operator!\n");
       return -1;
    }

    return result;
}

int finalAns(char str[])
{
    int i = 0; 
    int result,op1,op2;
    char curr;
    
    while (str[i] != '\0')
    {
        curr = str[i];
        
        if (isdigit(curr))
        {
            push(curr - '0');
        }else{
            op2 = (int)pop();
            op1 = (int)pop();
            result = calc(op1,op2,curr);
            push(result);
        }
        i++;
    }
    return pop();
}

void main()
{
    char str[20];
    printf("Enter string:");
    scanf("%s",str);

    int Ans = finalAns(str);

    printf("Answer : %d\n",Ans);
}