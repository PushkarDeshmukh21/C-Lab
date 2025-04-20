/*C program to perform linear search using pointers*/

#include<stdio.h>
#include<stdlib.h>

void LinearSearch(int *,int *,int);

void main()
{
    int n,key,i,*arr;

    printf("Enter number of array elements :");
    scanf("%d",&n);

    arr=(int *)malloc(n*sizeof(int));
    
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("Enter Element to be searched :");
    scanf("%d",&key);

    LinearSearch(arr,&key,n);

}

void LinearSearch(int *arr,int *key,int n)
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
        if(*(arr+i)==*key)
        {
            printf("%d found at %d position",*key,i+1);
           flag=1;
        }
        
    }
   
    if(flag==0)
    {
        printf("\nElement is absent");
    }
}
