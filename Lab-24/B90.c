//Binary Search
#include<stdio.h>

int binaryIterative(int arr[],int low,int high,int key)
{
    int mid;

    while (low <= high)
    {
        mid = (low + high)/2;

        if (arr[mid] == key)
        {
            return mid;
        }
        
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

        return -1;
    }
}

int binaryRecursive(int arr[],int low,int high,int key)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high)/2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            return binaryRecursive(arr,mid+1,high,key);
        }else{
            return binaryRecursive(arr,low,mid-1,key);
        }
        
        return -1;
    }    
}

void main()
{
    int n,key;

    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n],low = 0,high = n-1;

    printf("Entered element should be sorted:-\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter a key to search:");
    scanf("%d",&key);

    int posIt = binaryIterative(arr,low,high,key);
    int posRec = binaryRecursive(arr,low,high,key);

    if (posIt != -1)
        printf("%d is found at %d index...(Iterative)\n",key,posIt);
    else    
        printf("%d is not found....(Iterative)\n",key);

    if (posRec != -1)
        printf("%d is found at %d index...(Recursive)",key,posIt);
    else    
        printf("%d is not found....(Recursive)",key);
}