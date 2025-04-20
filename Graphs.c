#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100 
int graph[MAX][MAX], visited[MAX]; 
int nodes, edges; 
void createGraph() { 
 int i, x, y; 
 printf("Enter the number of nodes and edges: "); 
 scanf("%d %d", &nodes, &edges); 
 for (i = 0; i < edges; i++) { 
 printf("Enter the source and destination nodes of edge %d: ", i + 1); 
 scanf("%d %d", &x, &y); 
 graph[x][y] = 1; 
 graph[y][x] = 1; 
 } 
} 
void depthFirstSearch(int node) { 
 int i; 
 printf("%d ", node); 
 visited[node] = 1; 
 for (i = 0; i < nodes; i++) { 
 if (graph[node][i] == 1 && !visited[i]) 
 depthFirstSearch(i); 
 } 
} 
void breadthFirstSearch(int node) { 
 int i, queue[MAX], front = 0, rear = 0; 
 printf("%d ", node); 
 visited[node] = 1; 
 queue[rear++] = node; 
 while (front != rear) { 
 node = queue[front++]; 
 for (i = 0; i < nodes; i++) { 
 if (graph[node][i] == 1 && !visited[i]) { 
 printf("%d ", i); 
 visited[i] = 1; 
 queue[rear++] = i; 
 } 
 } 
 } 
} 
int main() { 
 int choice, startNode; 
 createGraph(); 
 while (1) { 
 printf("\nGraph Traversal Techniques:\n"); 
 printf("1. Depth First Search\n"); 
 printf("2. Breadth First Search\n"); 
 printf("3. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 for (int i = 0; i < nodes; i++) visited[i] = 0; 
 printf("Enter the starting node for DFS: "); 
 scanf("%d", &startNode); 
 depthFirstSearch(startNode); 
 break; 
 case 2: 
 for (int i = 0; i < nodes; i++) visited[i] = 0; 
 printf("Enter the starting node for BFS: "); 
 scanf("%d", &startNode); 
 breadthFirstSearch(startNode); 
 break; 
 case 3: 
 exit(0); 
 default: 
 printf("Invalid choice\n"); 
 } 
 } 
 return 0; 
}