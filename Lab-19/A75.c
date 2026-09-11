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
    if (root == NULL)
    {
        return NULL;
    }
    if (root->Info == x)
    {
        return root;
    }else if (x < root->Info)
    {
        return Search(root->lptr,x);
    }else{
        return Search(root->rptr,x); 
    }
}

struct Node *Delete(struct Node *root,int x)
{
    if (Search(root,x) == NULL)
    {
        printf("%d not found in tree...\n",x);
        return NULL;
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
        preorder(root->lptr);
    }
    if(root->rptr != NULL)
    {
        preorder(root->rptr);
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
        postorder(root->lptr);
    }
    if(root->rptr != NULL)
    {
        postorder(root->rptr);
    }
    printf("%d ",root->Info);
}

void main()
{
    int choice,x;
    struct Node *root = NULL,*found;

    do
    {
        printf("\n---------------------------------------------------------------\n");
        printf("1.Insert a node\n2.Delete a node\n3.Search a node\n4.Preorder Traversal\n");
        printf("5.Postorder Traversal\n6.Inorder Traversal\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to insert:");
            scanf("%d",&x);
            root = Insert(root,x);
            break;
        
        case 2:
            printf("Enter a number to delete:");
            scanf("%d",&x);
            root = Delete(root,x);
            break;

        case 3:
            printf("Enter a nuber to search in tree:");
            scanf("%d",&x);
            found = Search(root,x);
            if (found == NULL)
                printf("%d is not found...",x);
            else
                printf("%d is found...",found->Info);
            break;

        case 4:
            preorder(root);
            break;

        case 5:
            postorder(root);
            break;

        case 6:
            inorder(root);
            break;

        default:
            printf("Invalide choice...Try Again...!\n");
            break;
        }

    } while (choice <= 6);
    
}