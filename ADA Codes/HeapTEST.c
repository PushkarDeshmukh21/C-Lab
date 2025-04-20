#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int H[], int n, int*count) 
{
    int i, parent, value, j, heap;
    
    for (i = n / 2; i >= 1; i--)
    {
        parent = i;
        value = H[parent];
        heap = 0;
        
        while (!heap && (2 * parent ) <= n)
        {
            j = 2 * parent;
            
            if (j < n)
            {
               *count+=1;
               if (H[j] < H[j + 1])
               {
                  j++;
               } 
            }   
            
            *count+=1;
            if (value >= H[j])
            {
                heap = 1;
            }    
                
            else 
            {
                H[parent] = H[j];
                parent = j;
            }
        }
        
        H[parent] = value;
    }
    
}

void heapSort(int arr[], int n, int*count)
{
    while(n>1)
    {
       heapify(arr,n,count);
    
       swap(&arr[1], &arr[n]);
    
       n--;
    }   
}

/*void printArray(int arr[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/

int main() {
    int n = 10, arr[110];
    FILE*fp = fopen("results.txt","w");
    if(fp == NULL)
      exit(2);
      
    srand(time(NULL));  
    while(n!=110)
    {
       int count = 0;
       int arr[n+1];
       arr[0] = -1;
       fprintf(fp,"%d\t",n);
    
       for(int i = 1; i<=n; i++)
          arr[i] = n+1-i;
    
       heapSort(arr,n, &count);
       fprintf(fp,"%d\t",count);
    
       count = 0;
       for(int i = 1; i<=n; i++)
          arr[i] = i;
        
        heapSort(arr,n, &count);
       fprintf(fp,"%d\t",count);
       
       count = 0;
       for(int i = 1; i<=n; i++)
          arr[i] = rand()%1000;
          
        heapSort(arr,n, &count);
       fprintf(fp,"%d\n",count);  
    
       n+=10;   
    }
    
    fclose(fp);
    return 0;
}

