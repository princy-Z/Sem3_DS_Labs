#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Info = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *Insert(struct Node *root)
{
    int info;
    printf("Enter info:");
    scanf("%d",&info);

    if (info == -1)
        return root;

    if (root == NULL)
       root = CreateNode(info);
    
    printf("Left insert:\n");
    root->left = Insert(root->left);

    printf("Right insert\n");
    root->right = Insert(root->right);

    return root;
}

int checkHeight(struct Node *root)
{
    if (root == NULL)
        return 1;

    return  1 + ((checkHeight(root->left) > checkHeight(root->right)) ? checkHeight(root->left) : checkHeight(root->right));
}

int isBalance(struct Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int leftheight = checkHeight(root->left);
    int rightheight = checkHeight(root->right);

    return abs(leftheight - rightheight) <= 1 && isBalance(root->left) && isBalance(root->right) ; 
}

void main()
{
    struct Node *root = NULL;
    int left, right;

    root = Insert(root);

    if (isBalance(root))
        printf("True");
    else
        printf("False");

}