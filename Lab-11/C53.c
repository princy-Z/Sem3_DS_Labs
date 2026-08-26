#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
};

int addpoly(struct Node p1[],int t1,struct Node p2[],int t2,struct Node sum[])
{
    int i = 0, j = 0, k = 0;
    
    while(i < t1 && j < t2)
    {
        if (p1[i].exp > p2[j].exp)
        {
            sum[k++] = p1[i++];
        }
        else if (p1[i].exp < p2[j].exp)
        {
            sum[k++] = p2[j++];
        }
        else{
            int S = p1[i].coeff + p2[j].coeff;
            if (S != 0)
            {
                sum[k].coeff = S;
                sum[k].exp = p1[i].exp;
                k++;
            }
            i++;
            j++;
        } 
    }
    while (i < t1)
    {
        sum[k++] = p1[i++];
    }
    while (j < t2)
    {
        sum[k++] = p2[j++];
    }
    return k;
}

void sortpoly(struct Node p[], int t)
{
    for (int i = 0; i < t - 1; i++) 
    {
        for (int j = 0; j < t - i - 1; j++) 
        {
            if (p[j].exp < p[j + 1].exp) 
            {
                struct Node temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int simplifyPoly(struct Node p[], int t)
{
    for (int i = 0; i < t - 1; i++) 
    {
        if (p[i].exp == p[i + 1].exp) 
        {
            p[i].coeff += p[i + 1].coeff; 

            for (int j = i + 1; j < t - 1; j++) {
                p[j] = p[j + 1];
            }
            t--; 
            i--; 
        }
    }
    return t;
}

void display(struct Node sum[],int k)
{
    for (int i = 0; i < k; i++)
    {
        if (sum[i].exp == 1)
        {
            printf("%dx" ,sum[i].coeff,sum[i].exp);
        }
        else if (sum[i].exp == 0)
        {
            printf("%d" ,sum[i].coeff,sum[i].exp);
        }
        else{
            printf("%dx^%d " ,sum[i].coeff,sum[i].exp);
        }
        if (i < k-1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    int t1 = 3,t2 = 3;

    struct Node p1[t1], p2[t2],sum[20];

    for (int i = 0; i < t1; i++)
    {
        printf("Enter coeff of poly1:");
        scanf("%d",&p1[i].coeff);
        printf("Enter exp of poly1:");
        scanf("%d",&p1[i].exp);
    }
    for (int i = 0; i < t2; i++)
    {
        printf("Enter coeff of poly2:");
        scanf("%d",&p2[i].coeff);
        printf("Enter exp of poly2:");
        scanf("%d",&p2[i].exp);
    }

    sortpoly(p1, t1);
    sortpoly(p2, t2);

    t1 = simplifyPoly(p1,t1);
    t2 = simplifyPoly(p2,t2);
    
    int k = addpoly(p1 ,t1 ,p2 ,t2 ,sum);

    display(sum , k);

    return 0;
}