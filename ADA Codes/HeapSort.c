#include<stdio.h>
#include<stdlib.h>

int count = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n){
   for(int i=n/2;i>0;i--)
   {
    int k=i;
    int v=arr[k];
    int heap=0;
    while (!heap && 2*k<=n)
    {   
        int j=2*k;
        if(j<n){
            arr[j]<arr[j+1];
            j+=1;
        }
        count++;
        if(v>=arr[j]){
            heap=1;
        }
        else
        {count++;
            arr[k]=arr[j];
            k=j;
        }
    }
    arr[k]=v;
   }
}

void heap(int arr[], int n){
    for(int i = n/2 -1 ; i>-1; --i){
        heapify(arr, n);
    }

    for(int i = n-1; i>-1; --i){
        swap(&arr[i], &arr[0]);
        heapify(arr, i);
    }
}

void main(){


    FILE *fp=fopen("HeapSort.txt","w");
   

    for(int n = 10; n<=100; n+=10){
        int arr[n];

        // best case
        for(int i = 0; i<n; ++i)
            arr[i] = n -i;
        heap(arr, n);
        fprintf(fp, "%d\t%d\t",n,count);
        count = 0;

        // worst case
        for(int i = 0; i<n; ++i)
            arr[i] = i;
        heap(arr, n);
        fprintf(fp, "%d\t",count);
        count = 0;

        // avg case
        for(int i = 0; i<n/2; ++i)
            arr[i] = rand()%100;
        heap(arr, n);
        fprintf(fp, "%d\n",count);
        count = 0;
    }
}