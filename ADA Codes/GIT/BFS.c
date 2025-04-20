#include<stdio.h>
#include<stdlib.h>

int cyclic = 0, n;

void dfs(int graph[][n], int cur, int parent, int *vis){
    printf("%d  ", cur);
    vis[cur] = 1;

    for(int next = 0; next<n; ++next){
        if (graph[cur][next]){
            if ( next != parent && vis[next]){
                cyclic = 1;
            }

            if ( !vis[next] )
                dfs(graph, next, cur, vis);
        }
    }
}

void main(){
    printf("Enter num. of vertices >> \n");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter Adjacency matrix >> ");
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &graph[i][j]);

    int *vis = (int *)calloc(sizeof(int), n);

    printf("\n\nConnected Components >> \n");
    for(int i = 0; i<n; ++i){
        if ( !vis[i] ){
            dfs(graph, i, -1, vis);
            printf("\n");
        }
    }

    if ( cyclic )
        printf("Graph is cyclic\n");
    else
        printf("Graph is acyclic");
}