//29. Write a program to merge two unsorted arrays. 
#include<stdio.h>

void main()
{
    int n1,n2,i;

    printf("Enter no. of elements in array-1:");
    scanf("%d",&n1);

    printf("Enter no. of elements in array-2:");
    scanf("%d",&n2);

    int A[n1],B[n2],C[n1+n2];

    for (i = 0; i < n1; i++)
    {
        printf("Enter a element in array-1:");
        scanf("%d",&A[i]);
    }

    for (i = 0; i < n2; i++)
    {
        printf("Enter a element in array-2:");
        scanf("%d",&B[i]);
    }

    for (i = 0; i < n1; i++)
    {
        C[i] = A[i];
    }

    for (i = 0; i < n2; i++)
    {
        C[n1+i] = B[i];
    }
    
    for (i = 0; i < (n1+n2); i++)
    {
        printf("%d",C[i]);
    }
}