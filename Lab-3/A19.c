//19. Write a program to find position of the smallest number & the largest number 
//from given n numbers.
#include<stdio.h>

void main()
{
    int n,minp=0,maxp=0;

    printf("Enter total no. of element:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
       printf("Enter %d Element:",i+1);
       scanf("%d",&arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (max <= arr[i])
        {
            max = arr[i];
            maxp = i+1;
        }
        else{
            min = arr[i];
            minp = i+1;
        } 
    }
    printf("largest num is %d at %d position\n",max,maxp);
    printf("smallest num is %d at %d position\n",min,minp);
}