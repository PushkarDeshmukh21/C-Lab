// Graph implementation using adjacency list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

// Graph Creation & Display
void createGraph(node*[], int);
void displayGraph(node*[], int);
node* createEdge(int);
int checkEdge(node*[], int, int);

// BFS Traversal
void bfs(node*[], int[], int);

// Connectivity Check
int isConnected(node*[], int);

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int visited[n];
    for (int i = 0; i < n; i++)
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
    printf("\n\nEnter a vertex to perform the BFS from: ");
    scanf("%d", &vtx);
    if (vtx < 1 || vtx > n)
    {
        printf("\nEnter a valid vertex!\n");
        exit(1);
    }
    bfs(graph, visited, --vtx);

    int connected = isConnected(graph, n);
    if (connected)
    {
        printf("\nThe graph is connected.\n");
    }
    else
    {
        printf("\nThe graph is not connected.\n");
        printf("Connected components:\n");
        int* visitedComponents = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            visitedComponents[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visitedComponents[i])
            {
                printf("Component: ");
                bfs(graph, visitedComponents, i);
                printf("\n");
            }
        }
        free(visitedComponents);
    }

    return 0;
}

void createGraph(node* graph[], int n)
{
    int i = 0, j;

    while (i != -1)
    {
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
    while (temp != NULL)
    {
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

void bfs(node* graph[], int visited[], int n)
{
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = n;
    visited[n] = 1;

    while (front < rear)
    {
        int currentVertex = queue[front++];

        printf("%d\t", currentVertex + 1);

        node* ptr = graph[currentVertex];
        while (ptr != NULL)
        {
            int neighborVertex = ptr->vertex;
            if (visited[neighborVertex] != 1)
            {
                queue[rear++] = neighborVertex;
                visited[neighborVertex] = 1;
            }
            ptr = ptr->next;
        }
    }

    free(queue);
}

int isConnected(node* graph[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int componentCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            componentCount++;
            bfs(graph, visited, i);
        }
    }

    if (componentCount == 1)
    {
        return 1; // Graph is connected
    }
    else
    {
        return 0; // Graph is not connected
    }
}