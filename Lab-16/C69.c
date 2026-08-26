#include<stdio.h>

#define size 10

int top = -1;
int s[size];

void push(int x)
{
    if (top > size)
    {
        printf("Stack overflow!\n");
        return;
    }else{
        top++;
        s[top] = x;
    }
}

int pop()
{
    int val;

    if (top == -1)
    {
        printf("Stack is empty...\n");
    }else{
        val = s[top];
        top--;
    }
    return val;
}

int isSort(int B[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (B[i] > B[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int n;

    printf("Enter size of array:");
    scanf("%d",&n);

    int A[n],B[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter A[%d] element:",i+1);
        scanf("%d",&A[i]);
    }
    int i = 0,k=0;

    while (i < size)
    {
        if (i == n-1)
        {
            push(A[i]);
            B[k++] = pop();
            i++;
        }else if (A[i + 1] > A[i])
        {
            push(A[i]);
            B[k++] = pop();
            i++;
        }else{
            push(A[i]);
            push(A[i+1]);

            B[k++] = pop();
            B[k++] = pop();

            i += 2;
        }
    } 
    
    if (isSort(B,n))
    {
        printf("YES");
    }else{
        printf("NO");
    }
}