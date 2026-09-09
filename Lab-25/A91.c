#include<stdio.h>

void main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    //Bubble Sort
    for (int j = 0; j < n-1; j++)
    {
        if (arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d",arr[i]);

}