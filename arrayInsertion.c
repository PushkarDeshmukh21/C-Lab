#include<stdio.h>
#include<stdlib.h>
void insertion(int *,int *,int ,int );
void display(int *,int );
void read(int *,int );
void main()
{
    int size,value,index,*arr;
    printf("Enter Size of array");
    scanf("%d",&size);
    arr=(int *)malloc(size*sizeof(int));

    read(arr,size);

    printf("Enetr array element and index");
    scanf("%d%d",&value,&index);

    insertion(arr,&size,value,index);
    

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

void insertion(int *arr,int *n,int value,int index)
{
    if(index>0 && index<= (*n))
    {
        arr=(int *)realloc(arr,(*(n+1))*sizeof(int));
        for(int i=*(n-1);i>=index;i--)
        {
            *(arr+i+1)=*(arr+i);
        }
        *(arr+index)=value;
        *(n)+=1;
        display(arr,*n);
    }
    else
    {
        printf("Invalid index");
    }
} 