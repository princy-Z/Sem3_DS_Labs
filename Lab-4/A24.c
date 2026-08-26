//24. Write a program to insert a number at a given location in an array. 
#include<stdio.h>

void main()
{
    int n,pos,value;
    int arr[10];

    printf("Enter total no. of element:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    printf("Enter position where element should insert:");
    scanf("%d",&pos);

    printf("Enter a value to be insert:");
    scanf("%d",&value);

    for (int i = n-1 ; i >= pos-1 ; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = value;
    n++;

    printf("Array after insertion:");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",arr[i]);
    }
}