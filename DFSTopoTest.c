// Graph implemented by adjacency list

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

/////// Graph Creation & Display
void createGraph(node*[], int);
void displayGraph(node*[], int);
node* createEdge(int);
int checkEdge(node*[], int, int);

/////// DFS Traversal
void dfs(node*[], int[], int);
void dfsTopSort(node*[], int[], int[], int, int*);

////// Connectivity check
void checkConnectivity(node*[], int[], int);

////// Connected components
void displayConnectedComponents(node*[], int[], int);

////// Acyclicity
int isAcyclic(node*[],int);
int isAcyclicDFS(node*[],int, int, int[], int[]);

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }

    node* graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }

    createGraph(graph, n);
    displayGraph(graph, n);

    int vtx;

    printf("\n\nEnter a vertex to perform the dfs from : ");
    scanf("%d",&vtx);
    if(vtx < 1 || vtx > n)
    {
        perror("\nEnter valid vertex!!\n");
        exit(1);
    }
    dfs(graph, visited, --vtx);

    if (isAcyclic(graph,n))
    {
        int topSorted[n];
        for(int i=0; i<n; i++)
            visited[i] = 0;

        for(int i=0; i<n; i++)
            topSorted[i] = 0;

        int current = 0;
        dfsTopSort(graph,visited,topSorted,0,&current);

        current--;
        printf("\n\nTopological sorting after choosing vertex 1 as starting vertex...\n");
        for(int i=current; i>=0; i--)
           printf("%d\t",topSorted[i]);
        printf("\n");
    }
    else
        printf("\nThe graph is cyclic, so topological sorting is not possible.\n");

    return 0;
}

void createGraph(node* graph[], int n)
{
    int i = 0, j;

    while (i != -1) {
        printf("\nEnter '-1' to stop!\n");
        printf("A directed edge exists from: ");
        scanf("%d", &i);

        if (i == -1)
            break;

        printf("                         to: ");
        scanf("%d", &j);

        i--;
        j--;

        if (i >= n || j >= n)
        {
            printf("\nEnter valid vertices!\n");
        }

        else
        {
            int check = checkEdge(graph, i, j);
            if (!check)
            {
                node* newnode = createEdge(j);

                if (graph[i] == NULL)
                {
                    graph[i] = newnode;
                }

                else
                {
                    node* temp = graph[i];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }

            else
            {
                printf("\nEdge already exists from %d to %d!\n", i + 1, j + 1);
            }
        }
    }
}

node* createEdge(int vertexNo)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->vertex = vertexNo;
    newnode->next = NULL;
    return newnode;
}

int checkEdge(node* graph[], int i, int j)
{
    node* temp = graph[i];
    while (temp != NULL) {
        if (temp->vertex == j)
        {
            return 1; // Edge already exists
        }
        temp = temp->next;
    }
    return 0; // Edge does not exist
}

void displayGraph(node* graph[], int n)
{
    printf("\n***************  Graph Display  ***************\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nVertex : %d ->", i + 1);
        node* temp = graph[i];
        while (temp != NULL)
        {
            printf("-> %d  ", (temp->vertex) + 1);
            temp = temp->next;
        }
    }
    printf("\n***********************************************\n");
}

void dfs(node*graph[], int visited[], int n)
{
    visited[n] = 1;
    printf("\nVertex %d visited.",n+1);
    node*temp = graph[n];
    while(temp != NULL)
        {
                if(visited[temp->vertex]==0)
                        dfs(graph, visited, temp->vertex);
                temp = temp->next;
        }
}

/*void checkConnectivity(node*graph[], int visited[], int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nChecking connectivity from the vertex 1\n");
    dfs (graph, visited, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nThe graph is not connected.\n");
            displayConnectedComponents(graph, visited, n);
            return;
        }
    }

    printf("\nThe graph is connected.\n");
}

void displayConnectedComponents(node*graph[], int visited[], int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int component = 1;
    printf("\nConnected Components:\n");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Component %d: ", component);
            dfs(graph, visited, i);
            printf("\n");
            component++;
        }
    }
}*/

int isAcyclic(node*graph[], int n)
{
    int visited[n];
    int recursionStack[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        recursionStack[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (isAcyclicDFS(graph, n, i, visited, recursionStack))
            return 0;
    }

    return 1;
}


int isAcyclicDFS(node*graph[], int n, int v, int visited[], int recursionStack[])
{
    if (!visited[v])
    {
        visited[v] = 1;
        recursionStack[v] = 1;

        for (int j = 0; j < n; j++)
        {
            if (checkEdge(graph,v,j))
            {
                if (!visited[j] && isAcyclicDFS(graph, n, j, visited, recursionStack))
                    return 1;
                else if (recursionStack[j])
                    return 1;
            }
        }
    }

    recursionStack[v] = 0;
    return 0;
}

void dfsTopSort(node*graph[], int visited[], int topSorted[], int vtx, int*current)
{
   visited[vtx] = 1;

    node*temp = graph[vtx];
    while(temp != NULL)
        {
                if(visited[temp->vertex]==0)
                        dfsTopSort(graph, visited, topSorted, temp->vertex, current);
                temp = temp->next;
        }
    vtx++;
    topSorted[*current] = vtx;
    *current+=1;
}