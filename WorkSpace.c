#include<stdio.h>
#include<stdlib.h>
int *twoSum(int *,int ,int,int *);
void main()
{   int numsSize=4;
    int target =9;
    int *returnSize;
    int *nums=(int *)malloc(4*sizeof(int));
    for(int i=0;i<4;i++)
    {
        scanf("%d",&(*(nums+i)));
    }
    for(int j=0;j<4;j++)
    {
        printf("%d",*(nums+j));
    }
    returnSize=twoSum(nums,numsSize,target,returnSize);
     for(int j=0;j<nums;j++)
    {
        printf("\n%d",*(returnSize+j));
    }
    
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize=(int *)malloc(2*sizeof(int));
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if((*(nums+i) + *(nums+j))==target)
            {
                *(returnSize+0)=i;
                *(returnSize+1)=j;
            }
        }
    }
   return returnSize;
}