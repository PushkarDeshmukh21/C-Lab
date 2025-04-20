#include<stdio.h>
#include<stdlib.h>
void delete(int *,int *,int );
void display(int *,int );
void read(int *,int );
void main()
{
    int size,index,*arr;
    printf("Enter Size of array");
    scanf("%d",&size);
    arr=(int *)malloc(size*sizeof(int));

    read(arr,size);

    printf("Enter index of deletion element");
    scanf("%d",&index);

    delete(arr,&size,index);
    

}

void read(int *arr,int n)
{
     printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
}

void display(int *arr,int n)
{
    
    for(int i=0;i<n;i++)
    {
        printf("\t%d",*(arr+i));
    }
}

void delete(int *arr,int *n,int index)
{
    if(index<=(*n))
    {
        for(int i=index;i<(*n);i++)
        {
            *(arr+i-1)=*(arr+i);
        }
        *n-=1;
        display(arr,*n);
    }
    else
    {
        printf("Invalid index");
    }
} 