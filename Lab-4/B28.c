//28. Write a program to delete duplicate numbers from an array. 
#include<stdio.h>

void main()
{
    int arr[100];
    int n;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a element:");
        scanf("%d",&arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n-1; k++)
                {
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        } 
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
}