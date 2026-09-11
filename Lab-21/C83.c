#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    char Name[20];
    int Phone;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(char name[],int phone)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->Name,name);
    newNode->Phone = phone;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *Insert(struct Node *root,char name[],int phone)
{
    if (root == NULL)
    {
        root = CreateNode(name,phone);
    }

    if (strcmp(root->Name,name) < 0)
    {
        root->right = Insert(root->right,name,phone);
    }
    else if (strcmp(root->Name,name) > 0)
    {
       root->left = Insert(root->left,name,phone);
    }

    return root;
}

struct Node *MinValue(struct Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node *Search(struct Node *root,char name[])
{
    if (root == NULL || (strcmp(root->Name,name)==0))
    {
        return root;
    }

    if (strcmp(root->Name,name) < 0)
    {
        return Search(root->right,name);
    }

    return Search(root->left,name); 
}

struct Node *Delete(struct Node *root,char name[])
{
    if (Search(root,name) == NULL)
    {
        printf("not found in tree...\n");
        return NULL;
    }
    
    if (root == NULL)
    {
        return NULL;
    }

    if (strcmp(root->Name,name) < 0)
    {
        root->right = Delete(root->right,name);
    }
    else if (strcmp(root->Name,name) > 0)
    {
        root->left = Delete(root->left,name);
    }
    else
    {
        if (root->left  == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = MinValue(root->right);
            strcpy(root->Name,temp->Name);
            root->Phone = temp->Phone;
            root->right = Delete(root->right, temp->Name);
        }
    }
    return root;
}

void ascOrder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!");
        return;
    }
    if (root->left != NULL)
    {
        ascOrder(root->left);
    }

    printf("name : %s ,phone : %d \n",root->Name,root->Phone);

    if(root->right != NULL)
    {
        ascOrder(root->right);
    }
}

void descOrder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!");
        return;
    }
    if (root->right != NULL)
    {
        descOrder(root->right);
    }

    printf("name : %s ,phone : %d \n",root->Name,root->Phone);

    if(root->left != NULL)
    {
        descOrder(root->left);
    }
}

void main()
{
    int phone,choice;
    char name[20];
    struct Node *root = NULL,*found;

    do
    {
        printf("----------------------------------------------------------------------\n");
        
        printf("1.Add new entry in phone book\n2.Remove entry from phone book\n");
        printf("3.Search phone number\n4.List all entries in ascending order of name\n5.List all entries in descending order of name\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter your name:");
            scanf(" %[^\n]",name);
            printf("Enter your phone number:");
            scanf("%d",&phone);
            root = Insert(root,name,phone);
            break;
        
        case 2:
            printf("Enter a name which you want to delete:");
            scanf(" %[^\n]",name);
            root = Delete(root,name);
            break;

        case 3:
            printf("Enter a name to search phone number:");
            scanf(" %[^\n]",name);
            found = Search(root,name);
            if (found != NULL) {
                printf("Phone number: %d\n", found->Phone);
            } else {
                printf("Not found!\n");
            }
            break;

        case 4:
            ascOrder(root);
            break;

        case 5:
            descOrder(root);
            break;

        default:
            printf("Invalid choice...try again...!");
            break;
        }
    } while (choice <= 5);
}