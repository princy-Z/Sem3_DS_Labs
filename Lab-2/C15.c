//15. WAP to print Armstrong number from 1 to 1000.
#include<stdio.h>
#include<math.h>

int power(int,int);

void main()
{
    int temp,sum,rem=0;
    for (int i = 0; i < 1000; i++)
    {
        temp = i;
        sum = 0;
        int count=0;

        while (temp != 0)
        {
            count++;
            temp = temp/10;
        }
        
        temp = i;

        while (temp != 0)
        {
            rem = temp%10;
            sum = sum + power(rem,count);
            temp = temp/10;
        }
        if (sum == i)
        {
            printf("%d ",i);
        }
    }
}

int power(int base,int exp)
{
    if (exp==0)
    {
        return 1;
    }
    else
    {
        return base * power(base,(exp-1));
    }
    
    
}