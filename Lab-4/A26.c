//26. Write a program to insert a number in an array that is already sorted in an 
//ascending order.
#include<stdio.h>

void main()
{
     int n,pos,value;
    int arr[10];

    printf("Enter total no. of element:");
    scanf("%d",&n);

    printf("Enter elements in ascending order:-\n");

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    printf("Enter a value to be insert:");
    scanf("%d",&value);

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > value )
    //     {
    //         pos = i;
    //         break;
    //     }
    // }
    
    int j=0;
    while (arr[j] < value)
    {
        j++;
        pos = j;
    }
    
    for (int i = n-1 ; i >= pos ; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = value;
    n++;

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

}