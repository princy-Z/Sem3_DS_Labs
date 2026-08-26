//23. WAP to sort the N names in an alphabetical order. 
#include<stdio.h>
#include<string.h>

void main()
{
    int n;
    char name[50][50],temp[50];

    printf("Enter no. of names:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a name:");
        scanf("%s",name[i]);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (strcmp(name[i],name[j]) > 0)
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        } 
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",name[i]);
    }
    
}