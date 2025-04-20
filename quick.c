#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int count = 0;

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hoare partition function
int hoarePartition(int arr[], int low, int high) {
  
    int i = low, j = high+1 , t = arr[low];
    do
    {    
        do
        {
            i++;
            count++;
        } while (arr[i] < t && i <= high);
        do
        {
            j--;
            count++;
        } while (arr[j] > t && j >= low);
        swap(&arr[i], &arr[j]);
    } while (i <= j);
    swap(&arr[i],&arr[j]);
    swap(&arr[low],&arr[j]);
    return j;
}


void generate(int arr[], int begin, int end) {
    if(begin<end){
        int middle=(begin+end)/2;
    generate(arr, begin, middle);

    swap(&arr[begin], &arr[middle]);

    generate(arr, middle + 1, end);

    }
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int split = hoarePartition(arr, low, high);
        quicksort(arr, low, split-1);
        quicksort(arr, split+1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp=fopen("bc.txt","w");
    int n=8;

    if(fp==NULL)
    printf("Error!!");

    srand(time(NULL));
    while(n!=1024)
    {
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=i+1;

        //Worst
        count=0;
        quicksort(arr,0,n-1);
        fprintf(fp,"%d\t%d\t",n,count);

       //best
        count=0;
      generate(arr,0,n-1);
      
      // for(int i=0;i<n;i++)
       //arr[i]=2;

        quicksort(arr,0,n-1);
        fprintf(fp,"%d\t",count);

       
         for(int i=0;i<n;i++)
         {   arr[i]=rand()%n;}
         count=0;

        quicksort(arr,0,n-1);
        fprintf(fp,"%d\n",count); 

        n*=2;
    }
    fclose(fp);
    return 0;
}