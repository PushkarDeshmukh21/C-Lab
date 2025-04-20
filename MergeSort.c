/*C program to perform Merge Sort*/

#include<stdio.h>
#include<stdlib.h>

void merge(int *,int ,int );
void mergesort(int *,int ,int );
void main()
{

    int *arr,n,i,start,end;
    printf("Enter number of array elements");
    scanf("%d",&n);

    start=0,end=n-1;
    printf("Enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);

    }

    mergesort(arr,start,end);
    printf("Sorted array is :");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));
    }
}

void mergesort(int *arr,int start,int end)
{
    int mid=start+(end-start)/2;
    if(start<end)
    {
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,end);
    }
}

void merge(int *arr,int start,int end)
{
    int mid=(start+end)/2;
    int len1= mid-start+1;
    int len2= end-mid;

    int *first=(int *)malloc(len1*sizeof(int));
    int *second=(int *)malloc(len2*sizeof(int));

    int i,j1,j2,k=start;
    for(i=0;i<len1;i++)
    {
        *(first+i)=*(arr+ k++);
    }
    k=mid+1;
    for(i=0;i<len2;i++)
    {
        *(second+i)=*(arr+ k++);
    }

    j1=0,j2=0;

    while(j1<len1&&j2<len2)
    {
        if(*(first+j1)<*(second+j2))
        {
            *(arr+ k++)=*(first+ j1++);
        }
        else{
            *(arr+ k++)=*(second+ j2++);
        }

    }

    while(j1<len1)
    {
        *(arr+ k++)=*(first+ j1++);
    }
    while(j2<len2)
    {
        *(arr+ k++)=*(second+ j2++);
    }
}