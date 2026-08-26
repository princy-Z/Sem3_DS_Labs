// 37. WAP to find the largest element in the array using Pointer. 

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
    int max = *p;

    for (int i = 0; i < n; i++)
    {
        if (max < *(p+i))
            max = *(p+i);
    }
    printf("LArgest Element : %d",max);
}