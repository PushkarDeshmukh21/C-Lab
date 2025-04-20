#include<stdio.h>
#include<stdlib.h>
void read(int *,int);
void display(int *,int );
void main()
{
    int size,*arr;
    printf("Enter Size of array");
    scanf("%d",&size);
    arr=(int *)malloc(size*sizeof(int));
    read(arr,size);
    display(arr,size);

}

void display(int *arr,int n)
{
    printf("Your array is");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",*(arr+i));
    }
}

void read(int *arr,int n)
{
     printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
}