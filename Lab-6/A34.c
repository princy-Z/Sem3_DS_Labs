// 34. WAP to allocate and de-allocate memory for int, char and float variable at runtime. 

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *i = (int*)malloc(sizeof(int));
    char *c = (char*)malloc(sizeof(char));
    float *f = (float*)malloc(sizeof(float));

    if (i == NULL || c == NULL || f == NULL)
    {
        printf("Memory allocation failed!");
    }
    
    printf("Enter a integer:");
    scanf("%d",i);

    printf("Enter a character:");
    scanf(" %c",c);

    printf("Enter a float number:");
    scanf("%f",f);

    printf("Int : %d\nChar : %c\nFloat : %f",*i,*c,*f);

    free(i);
    free(c);
    free(f);
}