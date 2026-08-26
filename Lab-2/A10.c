//10. WAP to reverse a number.
#include<stdio.h>

void main()
{
    int num,rem=0,sum=0;

    printf("Enter a number:");
    scanf("%d",&num);

    while (num!=0)
    {
        rem = num%10;
        sum = sum*10+rem;
        num=num/10;
    } 
    printf("reverse number : %d",sum);
}