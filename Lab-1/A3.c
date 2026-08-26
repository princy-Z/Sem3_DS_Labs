//3. WAP to determine whether the entered character is vowel or not.
#include<stdio.h>

void main()
{
    char C;

    printf("Enter a alfa.:");
    scanf("%c",&C);

    if (C=='A'|| C=='E'||C=='I'|| C=='O'||C=='U'|| C=='a'||C=='e'|| C=='i'||C=='o'|| C=='u')
    {
        printf("%c is vowel...",C);
    }
    else
    {
        printf("%c is not vowel...",C);
    }
    
}