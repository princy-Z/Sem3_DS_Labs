// 41. Write a program to implement a node structure for singly linked list. Read the 
// data in a node, print the node.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Info;
    struct Node *Link;
};

void main()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = 5;
    newNode->Link = NULL;

    printf("%d",newNode->Info);
    
}