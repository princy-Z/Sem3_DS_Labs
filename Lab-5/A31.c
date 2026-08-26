//31. Read two 2x2 matrices and perform addition of matrices into third matrix and 
//print it 
#include<stdio.h>

void main()
{
    int n;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    int arr1[n][n],arr2[n][n],sum[n][n],i,j;

    for (i = 0; i < n; i++)
    {   for ( j = 0; j < n; j++)
        {
            printf("Enter a element at arr[%d][%d]:",i,j);
            scanf("%d",&arr1[i][j]);
        } 
    }
    
    for (i = 0; i < n; i++)
    {   for ( j = 0; j < n; j++)
        {
            printf("Enter a element at arr[%d][%d]:",i,j);
            scanf("%d",&arr2[i][j]);
        } 
    }

    for (i = 0; i < n; i++)
    {   for ( j = 0; j < n; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        } 
    }

    for (i = 0; i < n; i++)
    {   for ( j = 0; j < n; j++)
        {
            printf("%d ",sum[i][j]);
        } printf("\n");
    }
}