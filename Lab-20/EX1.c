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

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!");
        return;
    }
    if (root->left != NULL)
    {
        inorder(root->left);
    }
    printf("%d[%d] ",root->Info,root->level);

    if(root->right != NULL)
    {
        inorder(root->right);
    }
}

void set_Level(struct Node *root,int count)
{
    if (root == NULL)
    {
        return;
    }
    root->level = count;

    set_Level(root->left,count + 1);
    set_Level(root->right,count + 1);
}

int get_Level(struct Node *root,int data)
{
    if (root == NULL)
        return -1;
    
    if (root->Info == data)
        return root->level;
    
    int left = get_Level(root->left,data);
    if (left != -1)
    {
        return left;
    }
    
    int right = get_Level(root->right,data);
    if (right != -1)
    {
        return right;
    }
    return -1;
}

void main()
{
    struct Node *root = NULL;

    root = Insert(root);

    set_Level(root,1);

    inorder(root);

    int level = get_Level(root,4);
    printf("%d",level);

}