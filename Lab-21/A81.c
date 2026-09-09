#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    int level;
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

int findPosition(int inorder[],int element,int n)
{
    for(int i=0; i<n; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

struct Node *solve(int inorder[],int preorder[],int *preIndex,int Instart,int Inend,int n)
{
    if(Instart > Inend)
        return NULL;

    int element = preorder[(*preIndex)];

    (*preIndex)++;

    struct Node *root = CreateNode(element);

    int position = findPosition(inorder,element,n);

    root->left = solve(inorder,preorder,preIndex,Instart,position-1,n);

    root->right = solve(inorder,preorder,preIndex,position+1,Inend,n);
    
    return root;
}

struct Node *builtTree(int inorder[],int preorder[],int n)
{
    int preIndex = 0;

    struct Node *root = solve(inorder,preorder,&preIndex, 0, n-1, n);

    return root;
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty!");
        return;
    }
    if (root->left != NULL)
    {
        postorder(root->left);
    }
    if(root->right != NULL)
    {
        postorder(root->right);
    }
    printf("%d ",root->Info);
}

void main()
{
    int n;

    int Inorder[] = {4,2,5,1,6,3};
    int Preorder[] = {1,2,4,5,3,6};

    n = sizeof(Inorder)/sizeof(Inorder[0]);

    struct Node *root = builtTree(Inorder,Preorder,n);

    postorder(root);
}