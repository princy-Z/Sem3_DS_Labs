//16. Write a program to read and display n numbers using an array. 
#include<stdio.h>

void main()
{
    int n;

    printf("Enter total no. of element:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    printf("Entered elements are:-\n");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",arr[i]);
    }
}