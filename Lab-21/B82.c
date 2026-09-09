#include<stdio.h>
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

struct Node *Insert(struct Node *root,int x)
{
    if (root == NULL)
        root = CreateNode(x);

    if (x < root->Info)
        root->left = Insert(root->left,x);

    else if (x > root->Info)
       root->right = Insert(root->right,x);
    
    if(x == root->Info)
        return root;

    return root;
}

int searchMin(struct Node *root)
{
    if (root == NULL)
        return 0;

    struct Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->Info;
}

int searchMax(struct Node *root)
{
    if (root == NULL)
        return 0;

    struct Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->Info;
}

void main()
{
    struct Node *root = NULL;

    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,10);
    root = Insert(root,40);
    root = Insert(root,1);

    int min = searchMin(root);
    int max = searchMax(root);

    printf("%d is smallest element...\n",min);
    printf("%d is highest element...\n",max);
}