//20. Write a program to find whether the array contains a duplicate number or not. 
#include<stdio.h>

void main()
{
    int n,isfound=0;

    printf("Enter total no. of element:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n-1 ; j++)
        {
            if (arr[i] == arr[j])
            {
                isfound=1;
                break;
            } 
        }
    }
    
    if (!isfound)
    {
        printf("Array has not duplicat number...");
    }
    else{
        printf("Array has duplicat number...");
    }
    
}