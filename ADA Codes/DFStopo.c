#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list

struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}


void DFS(struct Graph* graph, int vertex, int* visited, int* stack, int* top,int *botm) {
    visited[vertex] = 1;

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited, stack, top, botm);
        }

        temp = temp->next;
    }

    // Push the current vertex onto the stack

        stack[++(*botm)] = vertex;
}

int is_cyclic_util(struct Graph *graph,int vertex,int *visited,int *rec_stack)
{
        visited[vertex]=1;
        rec_stack[vertex]=1;
        struct Node *adjacency_list=graph->array[vertex].head;

        while(adjacency_list!=NULL){
                int connected_vertex=adjacency_list->vertex;

        if(!visited[connected_vertex] && is_cyclic_util(graph,connected_vertex,visited,rec_stack))
                return 1;
        else if(rec_stack[connected_vertex])
                return 1;

        adjacency_list = adjacency_list->next;
        }
        rec_stack[vertex]=0;
        return 0;
}

int is_cyclic(struct Graph *graph)
{       int numVertices=graph->numVertices;
        int visited[numVertices];
        int rec_stack[numVertices];
        for(int i=0;i<numVertices;i++){
                visited[i]=0;
                 rec_stack[i]=0;
        }
        for(int v=0;v<graph->numVertices;v++){
                if(!visited[v]){
                        if(is_cyclic_util(graph,v,visited,rec_stack))
                                return 1;
                }
        }
        return 0;
}


void topologicalSort(struct Graph* graph)
{
    int numVertices = graph->numVertices;
    int visited[numVertices];
    int stack[numVertices];
    int top = 0;
    int botm = -1;

    // Initialize visited array to all zeros
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS traversal on each unvisited vertex
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &top,&botm);
        }
    }

        printf("DFS Stack according to order of termination: \n");
        while(botm >= top)
        {
                printf(" %d \n",stack[botm--]);
                printf("____\n");
        }
        top=numVertices-1;

    printf("Topological Ordering: ");
    while (top<=botm) {
        printf("%d ", stack[botm--]);
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

        if(is_cyclic(graph)){
        printf("The graph is cyclic and topological sorting cannot be performed\n");
        }
        else{
                topologicalSort(graph);

        }



    return 0;
}