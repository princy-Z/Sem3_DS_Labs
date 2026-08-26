//8. WAP to find factorial of a number Using loop.
#include<stdio.h>

void main()
{
    int num,i=1,fact=1;

    printf("Enter a num:");
    scanf("%d",&num);

    while (i<=num)
    {
        fact = fact * i;
        i++;
    }

    printf("Factorial : %d",fact);
}