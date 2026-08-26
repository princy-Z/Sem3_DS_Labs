//13. WAP to print prime numbers between given interval.
#include<stdio.h>

void main()
{
    int start,end,isPrime;

    printf("Enter starting point:");
    scanf("%d",&start);

    printf("Enter ending point:");
    scanf("%d",&end);

    for (int i = start; i <= end; i++)
    {   isPrime = 1;
        if (i <= 1)
        {
            continue;
        }
        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
        {
            printf("%d ",i);
        }
    }
}