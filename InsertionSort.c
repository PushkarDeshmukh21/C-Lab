#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int count = 0;
FILE *ptr;
// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        if(arr[j]<key)
            count++;
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
 {
    int size = 10;
    srand(time(0));

    ptr = fopen("output.txt", "w");
    if (ptr==NULL)  
    {
        printf("File not created");
        exit(0);
    }
    
    while (size!=110)
    {
        int arr[size];
        fprintf(ptr, "%d\t", size);

        //Best Case
        for (int i = 0; i < size; i++)
        {
            arr[i]=i;
        }
        count = 0;
        insertionSort(arr, size);
        fprintf(ptr, "%d\t", count);

        //Avg case 
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand()%100;
        }
        count = 0;
        insertionSort(arr, size);
        fprintf(ptr, "%d\t", count);

        //Avg case 
        for (int i = 0; i < size; i++)
        {
            arr[i] = size-i;
        }
        count = 0;
        insertionSort(arr, size);
        fprintf(ptr, "%d\n", count);

        size+=10;
    }
    return 0;
    
}