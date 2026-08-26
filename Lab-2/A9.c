//9. WAP to find power of a number using loop.
#include<stdio.h>

void main()
{
    int base,exp,result=1,i=1;

    printf("Enter Base:");
    scanf("%d",&base);
    printf("Enter power:");
    scanf("%d",&exp);
    
    while (i<=exp)
    {
        result = result * base;
        i++;
    }
    printf("Power : %d",result);
}