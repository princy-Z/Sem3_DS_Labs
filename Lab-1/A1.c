//1. WAP to calculate area of a Circle (A = πr2).
#include<stdio.h>

void main()
{
    float radius;

    printf("Enter radius:");
    scanf("%f",&radius);

    float area = 3.14*radius*radius;

    printf("%f",area);
}