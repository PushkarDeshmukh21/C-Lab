#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int dest;
    struct Node* next;
} Node;


Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int i, n, e, o, d, v = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

   
    Node* adj[n];
    for (i = 0; i < n; i++)
        adj[i] = NULL;

    int* indeg = (int*)calloc(n, sizeof(int));
    int* toposort = (int*)calloc(n, sizeof(int));

    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges:\n");
    for (i = 0; i < e; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &o, &d);
        if (o < 1 || d < 1 || d > n || o > n) {
            printf("Invalid edge!\n");
            i--;
        } else {
           
            Node* newNode = createNode(d);
            newNode->next = adj[o - 1];
            adj[o - 1] = newNode;
            indeg[d - 1]++;
        }
    }

    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                toposort[v++] = i + 1;
                indeg[i] = -1;
                Node* temp = adj[i];
                while (temp != NULL) {
                    indeg[temp->dest - 1]--;
                    temp = temp->next;
                }
                break;
            }
        }
    }

    if (v == n) {
        printf("Topological sort of the given directed graph:\n");
        for (i = 0; i < n; i++)
            printf("%d->", toposort[i]);
    } else if (v < n)
        printf("Topological sort not possible, Cycle found!");

    
    for (i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(indeg);
    free(toposort);

    return 0;
}
