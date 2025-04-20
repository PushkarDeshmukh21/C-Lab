#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct List {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two vertices
void addEdge(struct List* adjList, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = adjList[dest].head;
    adjList[dest].head = newNode;
}

// Function to perform BFS traversal from a given source vertex
void BFS(struct List* adjList, int vertices, int* visited, int src) {
    int queue[vertices];
    int front = 0, rear = 0;

    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = adjList[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Function to check if the graph is cyclic using DFS
int isCyclicUtil(struct List* adjList, int v, int visited[], int parent) {
    visited[v] = 1;

    struct Node* temp = adjList[v].head;
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (visited[adjVertex] == 0) {
            if (isCyclicUtil(adjList, adjVertex, visited, v))
                return 1;
        } else if (adjVertex != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to check if the graph is cyclic
int isCyclic(struct List* adjList, int vertices) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    for (int v = 0; v < vertices; v++) {
        if (visited[v] == 0) {
            if (isCyclicUtil(adjList, v, visited, -1))
                return 1;
        }
    }
    return 0;
}

// Function to display connected components in the graph
void displayConnectedComponents(struct List* adjList, int vertices) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Connected Components:\n");

    for (int v = 0; v < vertices; v++) {
        if (visited[v] == 0) {
            printf("Component: ");
            BFS(adjList, vertices, visited, v);
            printf("\n");
        }
    }
}

void printAdjacencyList(struct List* adjList, int vertices) {
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = adjList[i].head;
        printf("Adjacency list of vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    struct List* adjList = (struct List*)malloc(vertices * sizeof(struct List));

    for (int i = 0; i < vertices; i++) {
        adjList[i].head = NULL;
    }

    printf("Enter the edges in the graph:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d: ", i + 1);
        scanf("%d%d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    printf("\n");

    printAdjacencyList(adjList,vertices);

    printf("\n");

    // Display connected components
    displayConnectedComponents(adjList, vertices);

    printf("\n");

    // Check if the graph is cyclic
    if (isCyclic(adjList, vertices)) {
        printf("The graph is cyclic.\n");
    } else {
        printf("The graph is acyclic.\n");
    }

    return 0;
}
