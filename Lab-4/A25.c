//25. Write a program to delete a number from a given location in an array. 
 
#include<stdio.h>

void main()
{
    int n,pos;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter a element:");
        scanf("%d",&arr[i]);
    }
    
    printf("Enter position to delete that element:");
    scanf("%d",&pos);

    for (int i = pos-1; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
}