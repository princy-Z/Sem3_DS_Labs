//21. Read n numbers in an array then read two different numbers, replace 1st 
//number with 2nd number in an array and print its index and final array. 
#include<stdio.h>

void main()
{
    int n,find,replace,index;

    printf("Enter total no. of element:");
    scanf("%d",&n);

    printf("Enter number which you want to replace:");
    scanf("%d",&find);

    printf("Enter number by which you want to replace:");
    scanf("%d",&replace);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
       if (arr[i] == find)
       {
         arr[i] = replace;
         index = i+1;
         break;
       }  
    }

    printf("Array:-\n");
    for (int i = 0; i < n; i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d is found at %d position...",find,index);
}