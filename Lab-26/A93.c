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

    //Insertion Sort
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
}