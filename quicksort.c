#include <stdio.h>
#include <stdlib.h>

int comparisonCount = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        int exchange = 0;
        while (arr[i] <= pivot) {
            exchange = 1;
            i++;
            comparisonCount++;  // Increment comparison count
        }
        if(exchange == 0)
          comparisonCount++;
        
        exchange = 0;
        while (arr[j] > pivot) {
            exchange = 1;
            j--;
            comparisonCount++;  // Increment comparison count
        }
        
        if(exchange == 0)
          comparisonCount++;
        
    
            swap(&arr[i], &arr[j]);
    
    }
     swap(&arr[i], &arr[j]);

    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE*fp = fopen("res.txt","w");
    
    int n=2;
    while(n!=1024)
    {
        int arr[n], i;
        for(i = 0; i<n; i++)
           arr[i] = i+1;
           
        comparisonCount = 0;  // Reset comparison count
        quickSort(arr, 0, n - 1);
        fprintf(fp,"%d\t%d\t",n,comparisonCount);  // for worst case
        
        for(i = 0; i<n; i++)
           arr[i] = rand()%n;      // random array
           
        comparisonCount = 0;  // Reset comparison count
        quickSort(arr, 0, n - 1);
        fprintf(fp,"\t%d\n",comparisonCount);  // for average case
        n*=2;
    }
    fclose(fp);

    return 0;

}