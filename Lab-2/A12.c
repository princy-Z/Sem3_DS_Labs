//12. WAP to check whether a number is prime or not. 
#include<stdio.h>

void main()
{
    int num,count=0;

    printf("Enter a number:");
    scanf("%d",&num);

    for (int i = 1; i <= num; i++)
    {
        if (num%i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        printf("%d is prime number...",num);
    }
    else
    {
        printf("%d is not prime number...",num);
    }
    
}