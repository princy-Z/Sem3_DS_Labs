// 33. Design anagram game using array.  
// => Allow a user to enter N words and store it in an array.  
// => Generate a random number between 0 to N-1.  
// => Based on the random number generated display the word stored at that 
//    index of an array and allow user to enter its anagram.  
// => Check whether the word entered by the user is an anagram of displayed 
//    number or not and display an appropriate message.  
// => Given a word A and word B. B is said to be an anagram of A if and only if the 
//    characters present in B is same as characters present in A, irrespective of 
//    their sequence. For ex: “LISTEN” == “SILENT” 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void sortingAlpha(char []);

void main()
{
    int n;

    printf("Enter no. of words:");
    scanf("%d",&n);

    char Words[n][10],Anagram[10];

    for (int i = 0; i < n; i++)
    {
        printf("Enter a word:");
        scanf("%s",Words[i]);
    }
    
    srand(time(0));
    int ran = rand()%n;

    printf("Selected Word is %s.\n",Words[ran]);
    printf("Enter anagram of above word:");
    scanf("%s",Anagram);

    sortingAlpha(Words[ran]);
    sortingAlpha(Anagram);

    if (strcmp(Words[ran],Anagram) == 0)
    {
        printf("Your given word is anagram...");
    }else{
        printf("Your given word is not anagram...");
    }
}

void sortingAlpha(char str[])
{
    char temp;

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = i+1; str[j] != '\0'; j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    } 
}