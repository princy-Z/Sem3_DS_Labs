//22. WAP to print Pascal triangle. 
#include<stdio.h>

void main()
{
    int n;

    printf("Enter no. of rows:");
    scanf("%d",&n);

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int k = n; k > i+1; k--)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
                printf("%d ",arr[i][j]);
            }
            else{
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
                printf("%d ",arr[i][j]);
            }  
        } 
        printf("\n");
    } 
}