#include<stdio.h>
#include<stdlib.h>

struct Node
{   int Info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *CreateNode(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    return newNode;
}

struct Node *Insert(struct Node *root,int x)
{
    if (root == NULL)
    {
        root = CreateNode(x);
    }

    if (x < root->Info)
    {
        root->lptr = Insert(root->lptr,x);
    }
    else if (x > root->Info)
    {
       root->rptr = Insert(root->rptr,x);
    }
    
    if(x == root->Info){
        return root;
    } 
    return root;
}

struct Node *MinValue(struct Node *root)
{
    while (root && root->lptr != NULL)
    {
        root = root->lptr;
    }
    return root;
}

struct Node *Search(struct Node *root,int x)
{
    if (root == NULL || root->Info == x)
    {
        return root;
    }

    if (x < root->Info)
    {
        return Search(root->lptr,x);
    }

    return Search(root->rptr,x); 
}

struct Node *Delete(struct Node *root,int x)
{
    if (Search(root,x) == NULL)
    {
        printf("%d not found in tree...\n",x);
        return root;
    }
    
    if (root == NULL)
    {
        return root;
    }

    if (x < root->Info)
    {
        root->lptr = Delete(root->lptr,x);
    }
    else if (x > root->Info)
    {
        root->rptr = Delete(root->rptr,x);
    }
    else
    {
        if (root->lptr  == NULL)
        {
            struct Node *temp = root->rptr;
            free(root);
            return temp;
        }
        else if (root->rptr == NULL)
        {
            struct Node *temp = root->lptr;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = MinValue(root->rptr);
            root->Info = temp->Info;
            root->rptr = Delete(root->rptr, temp->Info);
        }
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!");
        return;
    }
    if (root->lptr != NULL)
    {
        inorder(root->lptr);
    }
    printf("%d ",root->Info);
    if(root->rptr != NULL)
    {
        inorder(root->rptr);
    }
}

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty!");
        return;
    }
    printf("%d ",root->Info);

    if (root->lptr != NULL)
    {
        inorder(root->lptr);
    }
    if(root->rptr != NULL)
    {
        inorder(root->rptr);
    }
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty!");
        return;
    }
    if (root->lptr != NULL)
    {
        inorder(root->lptr);
    }
    if(root->rptr != NULL)
    {
        inorder(root->rptr);
    }
    printf("%d ",root->Info);
}

void main()
{
    struct Node *root = NULL,*found;

    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,10);
    root = Insert(root,40);
    root = Insert(root,1);

    inorder(root);
    printf("\n");

    root = Delete(root,10);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    found = Search(root,10);

    if (found == NULL)
        printf("%d is not found...",found->Info);
    else
        printf("%d is found...",found->Info);
}