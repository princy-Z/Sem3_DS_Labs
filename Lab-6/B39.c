// 39. WAP to check whether the string is Palindrome or not using Pointer. 
#include<stdio.h>
#include<string.h>

int main()
{
    char word[100];
    char *str = word;
    int found=1;
    int start = 0;
    int end = strlen(word)-1;

    printf("Enter a word:");
    scanf("%s",word);

    while (start < end)
    {
        if (*(str + start) != *(str + end))
        {
            found = 0;
            break;
        }
        start++;
        end--;
    }

    if (found == 1)
        printf("String is palidrome");
    else
        printf("String is not palidrome");
        
    return 0;
}