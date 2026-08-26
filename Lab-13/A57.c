#include<stdio.h>

int stack[5];
int top = -1;

void push(int x)
{
    if (top > 4)
    {
        printf("Stack overflow!\n");
        return;
    }else{
        top++;
        stack[top] = x;
    }
}

int pop()
{
    int val;

    if (top == -1)
    {
        printf("Stack is empty...\n");
    }else{
        val = stack[top];
        top--;
    }
    return val;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty...\n");
    }
    return stack[top];
}

int peep(int i)
{
    if (top - i + 1 < 0)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top - i + 1];
}

void change(int i,int newX)
{
    if (top == -1)
    {
        printf("Stack is empty...\n");
        return;
    }
    stack[top - i + 1] = newX;
}

void Display()
{
    if (top == -1)
    {
        printf("Stack is empty...\n");
        return;
    }

    while (top > -1)
    {
        printf("%d ",stack[top]);
        top--;
    }
}

void main()
{
    int x,choice;

    do
    {
        printf("1.push an element\n2.pop an element\n3.Display Queue\n4.peep\n5.change\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter an element:");
            scanf("%d",&x);
            push(x);
            break;

        case 2:
            pop();
            printf("\n");
            break;

        case 3:
            display();
            break;
        
        case 4:
            peep(2);
            break;

        case 5:
            printf("Enter new element to change:");
            scanf("%d",&x);
            change(2,x);
            break;

        default:
            printf("Invalid choice!");
            break;
        }
    }while (choice < 6);
}