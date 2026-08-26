// 40. WAP to define a C structure named Student 
//    (roll_no, name, branch and batch_no) and also to access the structure members using Pointer.
#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int roll_no;
    char name[50];
    char branch[30];
    int batch_no;
};

void main()
{
    struct Student *S1 = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter your roll no:");
    scanf("%d",&S1->roll_no);

    printf("Enter your name:");
    scanf(" %[^\n]",S1->name);

    printf("Enter your branch name:");
    scanf(" %[^\n]",S1->branch);

    printf("Enter your batch no:");
    scanf("%d",&S1->batch_no);

    printf("Name : %s\n",S1->name);
    printf("Roll No. : %d\n",S1->roll_no);
    printf("Branch : %s\n",S1->branch);
    printf("Batch No. : %d\n",S1->batch_no);
}
