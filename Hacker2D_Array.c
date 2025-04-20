#include<stdio.h>
#include<stdlib.h>
int Hour(int [6][6] ,int );
void main()
{
    printf("Enter 2D Array Matrix: ");
    int i,j,n=6;
    int arr[6][6];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Your matrix:  \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }

    int result=Hour(arr,n);
    printf("\n Result: %d",result);

}

int Hour(int arr[6][6],int n)

{   //printf("Entered fn: \n");
       int result=-63;
    int sum; 
    for(int i=0;i<n-2;i++)
    {  // printf("Hi: ");
        for(int j=0;j<n-2;j++)
        {//   printf("Hi u: ");
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
           printf("%d\t",sum);
            if(sum>result)
            {
                result=sum;
            }
        }
    }
     return result;
}
