#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void initigraph(struct Node* adjlist[],int visited[],int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        adjlist[i] = NULL;
        visited[i] = 0;
    }
}

void addEdge(struct Node* adjlist[],int src,int dest)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = dest;
    newNode->link = adjlist[src];
    adjlist[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = src;
    newNode->link = adjlist[dest];
    adjlist[dest] = newNode;
}

void DFS(struct Node* adjlist[],int visited[],int vertex)
{
    struct Node *save = adjlist[vertex];

    visited[vertex] = 1;
    printf("%d ",vertex);

    while (save != NULL)
    {
        int connectedVertex = save->info;
        if (!visited[connectedVertex])
        {
            DFS(adjlist,visited,connectedVertex);
        }
        save = save->link;
    }
}

void main()
{
    int ver;

    printf("Enter no of vertices:");
    scanf("%d",&ver);

    struct Node *adjlist[ver];
    int visited[ver];

    initigraph(adjlist,visited,ver);

    addEdge(adjlist,0,11);
    addEdge(adjlist,11,12);
    addEdge(adjlist,12,14);
    addEdge(adjlist,11,13);

    DFS(adjlist,visited,0);

}