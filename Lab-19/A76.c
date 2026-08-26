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

int isSame(struct Node *root1,struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if(root1 != NULL && root2 != NULL)
    {
        if (root1->Info == root2->Info && isSame(root1->left,root2->left) && isSame(root1->right,root2->right))
        {
            return 1;
        }
    }
    return 0;
}

void main()
{
    struct Node *root1 = NULL,*root2 = NULL;

    root1 = Insert(root1);
    printf("\n");
    root2 = Insert(root2);

    if (isSame(root1,root2))
        printf("Both trees are same...\n");
    else
        printf("Both trees are not same...\n");
}