// 38. WAP to sort the array elements using Pointer. 

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;

    printf("Enter no. of element:");
    scanf("%d",&n);

    int arr[n];
    int *p = arr,temp;

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",(i+1));
        scanf("%d",(p+i));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (*(p+i) > *(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
    printf("After Sorting:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(p+i));
    }
}