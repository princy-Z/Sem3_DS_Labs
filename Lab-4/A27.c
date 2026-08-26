//27. Write a program to delete a number from an array that is already sorted in an 
//ascending order. 
#include<stdio.h>

void main()
{
    int n,value;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter a element:");
        scanf("%d",&arr[i]);
    }
    
    printf("Enter a element to delete:");
    scanf("%d",&value);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            for (int j = i; j < n-1; j++)
            {
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
}