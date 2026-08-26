//8. WAP to find factorial of a number recursion.
#include<stdio.h>

int fact(int);

void main()
{
    int num;
    printf("Enter a num:");
    scanf("%d",&num);

    int c = fact(num);

    printf("factorial : %d",c);
}

int fact(int n)
{
    if(n == 0 || n == 1)
       return 1;
    else
       return n*fact(n-1);
}
 