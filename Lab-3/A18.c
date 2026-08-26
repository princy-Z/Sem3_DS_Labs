//18. Write a program to calculate average of first n numbers.
#include<stdio.h>

void main()
{
    int n,sum=0;

    printf("Enter ending point:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    float avg = sum/n;

    printf("%0.2f",avg);
}