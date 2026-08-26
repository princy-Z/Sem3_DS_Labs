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
        if (root1->Info == root2->Info && isSame(root1->left,root2->right) && isSame(root1->right,root2->left))
        {
            return 1;
        }
    }
    return 0;
}

int isSymmetric(struct Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    
    if (isSame(root->left,root->right))
    {
        return 1;
    }
    return 0;
}

void main()
{
    struct Node *root = NULL;

    root = Insert(root);

    if (isSymmetric(root))
        printf("Tree is Symmetric...\n");
    else
        printf("Tree is not Symmetric...\n");
}
