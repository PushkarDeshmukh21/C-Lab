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

// Function to create a graph with 'numVertices' vertices
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

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Recursive function to perform Depth-First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex, int* visited, int* stack, int* top) {
    visited[vertex] = 1;

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited, stack, top);
        }

        temp = temp->next;
    }

    // Push the current vertex onto the stack
    stack[++(*top)] = vertex;
}

// Function to perform a topological sort of the graph using DFS
void topologicalSort(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int visited[numVertices];
    int stack[numVertices];
    int top = -1;

    // Initialize visited array to all zeros
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS traversal on each unvisited vertex
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &top);
        }
    }

    printf("Topological Ordering: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
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

    printf("\nTopological Ordering:\n");
    topologicalSort(graph);

    return 0;
}
