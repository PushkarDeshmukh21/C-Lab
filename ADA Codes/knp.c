#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    if (a > b)  return a;
    else    return b;
}

void main(){
    int T[10][10], V[10] = {0}, W[10] = {0}, n, m;
    printf("Enter num of items >> ");
    scanf("%d", &n);
    printf("Enter the capacity of sack >> ");
    scanf("%d", &m);
    printf("Enter the weight and value >> \n");
    for(int i = 1; i<n+1; ++i)
        scanf("%d%d", &W[i], &V[i]);

    for(int i = 0; i<n+1; ++i){
        for(int j = 0; j<m+1; ++j){
            if ( i == 0 || j == 0 )
                T[i][j] = 0;
            else if (j < W[i])
                T[i][j] = T[i-1][j];
            else    
                T[i][j] = max(T[i-1][j], V[i] + T[i-1][j-W[i]]);
        }
    }
    printf("\n\nTABLE -> \n");
    for(int i = 0; i<n+1; ++i){
        for(int j = 0; j<m+1; ++j)
            printf("%d\t", T[i][j]);
        printf("\n");
    }

    printf("Max Value of sack >> %d\n", T[n][m]);

    printf("Composition of sack >> \n");
    for(int i = n; i>0; --i){
        if ( T[i][m] != T[i-1][m] ){
            printf("%d  ", i);
            m = m - W[i];
        }
    }
}