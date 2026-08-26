//17. Write a program to calculate sum of numbers from m to n.
#include<stdio.h>

void main()
{
    int start,end,sum=0;

    printf("Enter starting point:");
    scanf("%d",&start);

    printf("Enter ending point:");
    scanf("%d",&end);

    for (int i = start; i <= end; i++)
    {
        sum += i ;
    }
    printf("%d",sum);
}