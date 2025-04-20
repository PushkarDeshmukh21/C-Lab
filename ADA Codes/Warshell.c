#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct graph{
    int vertices;
    int edges;

}Graph;

void main()
{   
    Graph* matrix=(Graph *)malloc(sizeof(Graph));
    printf("Enter the total number of vertices: ");
    scanf("%d",& matrix->vertices);
    printf("Enter the total number of edges: ");
    scanf("%d",&matrix->edges);

    int ADJmatrix[matrix->vertices][matrix->vertices];
     for(int i=0;i<matrix->vertices;i++)
    {
        for(int j=0;j<matrix->vertices;j++)
        {
           ADJmatrix[i][j]=0;
        }
    }

    int src,dest;
    printf("Enter Edges from source to destination: \n");
    for(int i=0;i<matrix->edges;i++)
    {
        printf("Enter edge %d: ",i+1);
        scanf("%d%d",&src,&dest);
        ADJmatrix[src-1][dest-1]=1;       
    }


    for(int k=0;k<matrix->vertices;k++)
    {
        for(int i=0;i<matrix->vertices;i++)
        {
            for(int j=0;j<matrix->vertices;j++)
            {
                if(ADJmatrix[i][j]==0 && (ADJmatrix[i][k]==1 && ADJmatrix[k][j]==1))
                {
                    ADJmatrix[i][j]=1;
                }
            }
        }

    }   
}