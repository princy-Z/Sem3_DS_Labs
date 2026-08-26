// 35. WAP to get and print the array elements using Pointer. 
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;

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
        printf("%d ",*(p+i));
    }
}