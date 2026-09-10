#include<stdio.h>

void main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n], last = n-1;

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    //Bubble Sort
    for (int i = 0; i <= last; i++)
    {
        int Exchange = 0;

        for (int j = 0; j < last; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                Exchange++;
            }
        }

        if (Exchange == 0)
            printf("Array is sorted...");
            break;

        last--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);

}