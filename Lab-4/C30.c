//30. WAP to replace lowercase characters by uppercase & vice-versa in a user 
//specified string. 
#include<stdio.h>
#include<string.h>

void main()
{
    char sen[50];  
    char temp[50];

    printf("Enter your string:");
    gets(sen);

    for (int i = 0; i < strlen(sen) ; i++)
    {
        if (sen[i] >= 'a' && sen[i] <= 'z')
        {
            sen[i] = sen[i] - 32;
        }
        else if(sen[i] >= 'A' && sen[i] <= 'Z')
        {
            sen[i] = sen[i] + 32;
        }
    }
    puts(sen);
}