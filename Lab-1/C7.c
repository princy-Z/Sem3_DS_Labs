// 7. WAP to convert number of days into year, week & days [e.g. 375 days mean 1 
// year, 1 week and 3 days].
#include<stdio.h>

void main()
{
    int days,year,week;

    printf("Enter days:");
    scanf("%d",&days);

    year = days/365;
    days = days%365;
    week = days/7;
    days = days%7;

    printf("%d year %d weeks %d days",year,week,days);

}
