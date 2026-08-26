//32. Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
//and store result in third matrix and print it. 
#include<stdio.h>

void main()
{
    int r1,r2,c1,c2;

    printf("Enter no. of rows and cols of array-A:");
    scanf("%d %d",&r1,&c1);
    printf("Enter no. of rows and cols of array-B:");
    scanf("%d %d",&r2,&c2);

    int A[r1][c1],B[r2][c2];
    int mul[r1][c2];
    
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter element in A[%d][%d]:",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter element in B[%d][%d]:",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    if (c1 == r2)
    {
        
    for (int i = 0; i < r1; i++)
    {   
        for (int j = 0; j < c2; j++)
        {   mul[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                mul[i][j] += A[i][k] * B[k][j];
            }
            
        }
    }
    
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ",mul[i][j]);
        }printf("\n");
    }
     }else
    {
        printf("You can't multiply these arrays...");
    }
}