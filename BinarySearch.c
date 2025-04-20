/* C program to perform binary search using pointers*/

#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int *,int *,int );

void main()
{
    int *arr,n,i,key;
    printf("Enter the number of elements of array :");
    scanf("%d",&n);
    
    arr=(int *)malloc(n*sizeof(int));

    printf("Enter array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("Enter search element :");
    scanf("%d",&key);

    BinarySearch(arr,&key,n);

}

int BinarySearch(int *arr,int *key,int n)
{
    int low=0,mid,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
    
        if(*(arr+mid)==*key)
        {
            printf("\n%d is found at %d place",*key,mid+1);
            break;
        }
        else if(*key>*(arr+mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid+1;
        }
    }

    if(low>high)
    {
        printf("%d is not found",*key);
    }


}