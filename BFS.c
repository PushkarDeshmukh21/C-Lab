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

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Breadth-First Search (BFS) traversal
void BFS(struct Graph* graph, int startVertex, int* visited) {
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Connected Component: ");

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->vertex;

            // If the adjacent vertex is not visited, mark it as visited and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to check if the graph is connected using BFS
void checkConnectivity(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int visited[numVertices];

    // Initialize visited array to all zeros
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Perform BFS traversal on each unvisited vertex
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            BFS(graph, i, visited);
        }
    }
}

// Function to check if the graph has a cycle using DFS
int hasCycleUtil(struct Graph* graph, int currentVertex, int parent, int* visited) {
    visited[currentVertex] = 1;

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->array[currentVertex].head;
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        // If the adjacent vertex is not visited, then recur on it
        if (!visited[adjVertex]) {
            if (hasCycleUtil(graph, adjVertex, currentVertex, visited)) {
                return 1;
            }
        }
        // If an adjacent vertex is visited and not the parent of the current vertex, then there is a cycle
        else if (adjVertex != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check if the graph has a cycle
int hasCycle(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int visited[numVertices];

    // Initialize visited array to all zeros
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Check for a cycle in each unvisited vertex
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, -1, visited)) {
                return 1;
            }
        }
    }

    return 0;
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

    printf("\nGraph Analysis:\n");

    // Check connectivity
    printf("Connectivity: ");
    checkConnectivity(graph);

    // Check acyclicity
    int hasCycleResult = hasCycle(graph);
    if (hasCycleResult) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph is acyclic.\n");
    }

    return 0;
}
