#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct graph{
    int vertices;
    int edges;

}Graph;

#define INF 999

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
            if(i==j)
            ADJmatrix[i][j]=0;
            else
           ADJmatrix[i][j]=INF;
        }
    }

    int src,dest,wt;
    printf("Enter Edges from source to destination: \n");
    for(int i=0;i<matrix->edges;i++)
    {   
        printf("Enter edge %d: ",i+1);
        scanf("%d%d",&src,&dest);
        printf("Enter weight: ");
        scanf("%d",&wt);
        ADJmatrix[src-1][dest-1]=wt;       
    }


    for(int k=0;k<matrix->vertices;k++)
    {
        for(int i=0;i<matrix->vertices;i++)
        {
            for(int j=0;j<matrix->vertices;j++)
            {
                if(ADJmatrix[i][j] > (ADJmatrix[i][k]+ ADJmatrix[k][j]))
                {
                    ADJmatrix[i][j]=(ADJmatrix[i][k]+ ADJmatrix[k][j]);
                }
            }
        }

    }   

      for(int i=0;i<matrix->vertices;i++)
    {
        for(int j=0;j<matrix->vertices;j++)
        {
           printf("%d ",ADJmatrix[i][j]);
        }
        printf("\n");
    }

}