// 36. WAP to calculate the sum of n numbers using Pointer. 

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,sum=0;

    printf("Enter no. of element:");
    scanf("%d",&n);

    int arr[n];
    int *p = arr;

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",(i+1));
        scanf("%d",(p+i));
    }
    for (int i = 0; i < n; i++)
    {
        sum += *(p+i);
    }
    printf("Sum : %d",sum);
}