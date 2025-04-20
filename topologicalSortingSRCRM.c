#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

/////// Graph Creation & Display
void createGraph(node*[], int, int[]);
void displayGraph(node*[], int);
node* createEdge(int);
int checkEdge(node*[], int, int);

/////// Topological Sorting
void topSortSrcRemoval(node*[],int[],int[],int);

////// Acyclicity
int isAcyclic(node*[],int);
int isAcyclicDFS(node*[],int, int, int[], int[]);

int main() 
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int vtxIndegree[n];
    int topSort[n];
    for(int i=0; i<n; i++)
    {
        vtxIndegree[i] = 0;
        topSort[i] = 0;
    }

    node* graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }

    createGraph(graph, n, vtxIndegree);
    displayGraph(graph, n);
    
    if (isAcyclic(graph,n))
    {
        topSortSrcRemoval(graph,vtxIndegree,topSort,n);
        printf("\n\nTopological Sorting\n\n");
        for(int i = 0; i<n; i++)
           printf("%d\t",topSort[i]);
    }    
    else
    {
        printf("\nThe graph is cyclic, hence topological sorting is not possible\n");
    }
        
        
    return 0;
}

void createGraph(node* graph[], int n, int vtxIndegree[]) 
{
    int i = 0, j;

    while (i != -1) {
        printf("\nEnter '-1' to stop!\n");
        printf("edge exists from(src-dest): ");
        scanf("%d", &i);

        if (i == -1)
            break;
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
                vtxIndegree[j]+= 1;
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
    
}

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

void topSortSrcRemoval(node*graph[], int vtxIndegree[], int topSort[], int n)
{
    int flag = 1;
    int index = 0;
    while(flag)
    {
        int removeableVtx = 0;
        while(vtxIndegree[removeableVtx]!=0 && removeableVtx<n)
             removeableVtx+=1;
             
        if(removeableVtx == n)
          flag = 0;
          
        else
        {
            for(int i = 0; i<n; i++)
            {
                if(checkEdge(graph,removeableVtx,i))
                   vtxIndegree[i]-=1;
            }
            
            vtxIndegree[removeableVtx] = -1;
            topSort[index++] = ++removeableVtx;
         
        }
    }
    
}
