// 6. WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
// [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]. 
#include<stdio.h>

void main()
{
    int sec,min=0,hour=0;

    printf("Enter seconds:");
    scanf("%d",&sec);

    while (sec>=60)
    {
        min++;
        sec -= 60;
    }
    while (min>=60)
    {
        hour++;
        min -= 60;
    }
    
    printf("%d:%d:%d",hour,min,sec);
}