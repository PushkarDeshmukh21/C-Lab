#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int num_vertices;
    Node* adjacency_list[MAX_VERTICES];
} Graph;

Node* create_node(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;

    for (int i = 0; i < vertices; ++i)
        graph->adjacency_list[i] = NULL;

    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    Node* newNode = create_node(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;
}

void dfs(Graph* graph, int vertex, int* visited, int component_num, int* component) {
    visited[vertex] = 1;
    component[vertex] = component_num;

    Node* adjacency_list = graph->adjacency_list[vertex];
    while (adjacency_list != NULL) {
        int connected_vertex = adjacency_list->vertex;
        if (!visited[connected_vertex])
            dfs(graph, connected_vertex, visited, component_num, component);
        adjacency_list = adjacency_list->next;
    }
}

int is_connected(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int start_vertex = 0; // Start DFS from vertex 0

    dfs(graph, start_vertex, visited, 1, NULL);

    // Check if all vertices are visited
    for (int v = 0; v < graph->num_vertices; ++v) {
        if (!visited[v])
            return 0; // Graph is not connected
    }

    return 1; // Graph is connected
}

int is_cyclic_util(Graph* graph, int vertex, int* visited, int* rec_stack) {
    visited[vertex] = 1;
    rec_stack[vertex] = 1;

    Node* adjacency_list = graph->adjacency_list[vertex];
    while (adjacency_list != NULL) {
        int connected_vertex = adjacency_list->vertex;
        if (!visited[connected_vertex] && is_cyclic_util(graph, connected_vertex, visited, rec_stack))
            return 1;
        else if (rec_stack[connected_vertex])
            return 1;
        adjacency_list = adjacency_list->next;
    }

    rec_stack[vertex] = 0;
    return 0;
}

int is_cyclic(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int rec_stack[MAX_VERTICES] = {0};

    for (int v = 0; v < graph->num_vertices; ++v) {
        if (!visited[v]) {
            if (is_cyclic_util(graph, v, visited, rec_stack))
                return 1;
        }
    }

    return 0;
}

void find_connected_components(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int component[MAX_VERTICES] = {0};
    int num_components = 0;

    for (int v = 0; v < graph->num_vertices; ++v) {
        if (!visited[v]) {
            num_components++;
            dfs(graph, v, visited, num_components, component);
        }
    }

    if (num_components == 1) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");

        printf("It has %d connected component(s):\n", num_components);
        for (int i = 1; i <= num_components; ++i) {
            printf("Component %d: ", i);
            for (int v = 0; v < graph->num_vertices; ++v) {
                if (component[v] == i)
                    printf("%d ", v);
            }
            printf("\n");
        }
    }

    if (is_cyclic(graph)) {
        printf("The graph contains cycles.\n");
    } else {
        printf("The graph is acyclic.\n");
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    Graph* graph = create_graph(num_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("Enter the edges in the format 'source destination':\n");
    for (int i = 0; i < num_edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(graph, src, dest);
    }

    find_connected_components(graph);

    return 0;
}