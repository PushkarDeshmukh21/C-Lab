#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
bool inStack[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;

void initialize(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        visited[i] = false;
        inStack[i] = false;
        stack[i] = 0;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
}

bool DFS(int node, int n) {
    visited[node] = true;
    inStack[node] = true;
    stack[++top] = node;

    int i;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            if (!visited[i]) {
                if (DFS(i, n))
                    return true;
            } else if (inStack[i]) {
                return true; // Cycle detected
            }
        }
    }

    inStack[node] = false;
    top--;
    return false;
}

bool isAcyclic(int n) {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = false;
        inStack[i] = false;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, n))
                return false; // Graph contains a cycle
        }
    }

    return true; // Graph is acyclic
}

void topologicalSortDFS(int node, int n) {
    visited[node] = true;
    int i;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i])
            topologicalSortDFS(i, n);
    }
    stack[++top] = node;
}

void topologicalSort(int n) {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = false;
    }

    top = -1;
    for (i = 0; i < n; i++) {
        if (!visited[i])
            topologicalSortDFS(i, n);
    }

    printf("Topological Order: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    initialize(n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isAcyclic(n)) {
        printf("Graph is acyclic.\n");
        topologicalSort(n);
    } else {
        printf("Graph contains a cycle.\n");
    }

    return 0;
}
