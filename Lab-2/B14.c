//14. WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n). 
#include<stdio.h>

void main()
{
    int end,totalsum=0;

    printf("Enter ending point:");
    scanf("%d",&end);

    for (int i = 1; i <= end; i++)
    {
        int sum=0;

        for (int j = 1; j <= i; j++)
        {
            sum += j;
        }
        totalsum += sum;
    }
    
    printf("Total sum : %d",totalsum);
}