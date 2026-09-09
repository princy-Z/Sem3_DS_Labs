//Linear Search
#include<stdio.h>

int LinearSearch(int arr[],int n,int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}
void main()
{
    int n,key;

    printf("Enter size of array:");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter a key to search:");
    scanf("%d",&key);

    int pos = LinearSearch(arr,n,key);

    if (pos != -1)
        printf("%d is found at %d index...",key,pos);
    else    
        printf("%d is not found....",key);
}