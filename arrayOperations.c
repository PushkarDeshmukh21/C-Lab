#include<stdio.h>
#include<stdlib.h>

void read(int *,int );
void display(int *,int );
void insertPos(int *);
void insertKey(int * );
void insertOrder(int *);
void deletePos(int * );
void deleteKey(int *);
void searchKey(int *);
void searchPos(int *);
void arrRev(int *);


void stread(int a[100],int );
void stdisplay(int a[100], int );
void stinsertPos(int a[100]);
void stinsertKey(int a[100]);
void stinsertOrder(int a[100]);
void stdeletePos(int a[100]);
void stdeleteKey(int a[100]);
void stsearchKey(int a[100]);
void stsearchPos(int a[100]);
void starrRev(int a[100]);

int i,size,*arr,value,a[100],rev[100];
int indx;

void main()
{
int choice,method;

while(1)
{

printf("\nARRAY OPERATIONS\n");
printf("\n1.Array operations using Dynamic memory allocation\n2.Array operations using Static memory allocation\n");
printf("3.Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
printf("\nEnter the size of array :");
scanf("%d",&size);

if(choice==1)
{
    arr=(int *)malloc(size*sizeof(int));

read(arr,size);

}
if(choice==2)
{
    stread(a,size);
}


switch(choice)
{
    
case 1:
printf("\n1.Insert by position\n2.Delete by position\n3.Insert by key\n4.Delete by key\n5.Insert by Order\n6.Search by key\n7.Search by position\n8.Reverse Array\n");
printf("Enter your method: ");
scanf("%d",&method);

switch(method)
{
case 1:
insertPos(arr);
break;

case 2:
deletePos(arr);
break;

case 3:
insertKey(arr);
break;

case 4:
deleteKey(arr);
break;

case 5:
insertOrder(arr);
break;

case 6:
searchKey(arr);
break;

case 7:
searchPos(arr);
break;

case 8:
arrRev(arr);
break;
 
default:printf("Invalid Method!!");

}
break;

case 2:
printf("\n1.Insert by position\n2.Delete by position\n3.Insert by key\n4.Delete by key\n5.Insert by Order\n6.Search by key\n7.Search by position\n8.Reverse Array\n");
printf("Enter you method: ");
scanf("%d",&method);

switch(method)
{
case 1:
stinsertPos(a);
break;

case 2:
stdeletePos(a);
break;

case 3:
stinsertKey(a);
break;

case 4:
stdeleteKey(a);
break;

case 5:
stinsertOrder(a);
break;

case 6:
stsearchKey(a);
break;

case 7:
stsearchPos(a);
break;

case 8:
starrRev(a);
break;
 
default:printf("Invalid Method!!");

}
break;

case 3:exit(0);
default:printf("Invalid choice");
}
}
}

/* **********************************************************************************************************************************  */

//function to read array
void read(int *arr,int size)
{
printf("Enter array elements\n");
for(i=0;i<size;i++)
{
scanf("%d",arr+i);
}
}

//function to display array
void display(int *arr, int size)
{
printf("Your new array is :");
for(i=0;i<size;i++)
{
printf("\t %d", *(arr+i));
}
}

//function to insert element in array
void insertPos(int *arr)
{

  printf("Enter value of element and position : ");
scanf("%d%d",&value,&indx);

if(indx>0 && indx<=size)
{ size+=1;
arr=(int *)realloc(arr,((size) * sizeof(int)));
for(i=size-1;i>=indx;i--)
{

*(arr+i)=*(arr+i-1);
}

*(arr+indx-1)=value;


display(arr,size);
}
else
{
printf("Invalid Index");
}

}

//function to perform deletion
void deletePos(int *arr)
{

printf("Enter the value of position : ");
scanf("%d",&indx);
if(indx<=size)
{
for(i=indx-1;i<size;i++)
{

*(arr+i)=*(arr+i+1);
}
size-=1;
display(arr,size);
}
else
{
printf("Invalid Index");
}

}


//function to search element and insert if element absent
void insertKey(int *arr)
{
    int flag=0;
    printf("Enter the value of search element : ");
    scanf("%d",&value);
    for(i=0;i<size;i++)
    {
        if(*(arr+i)==value)
        {
        printf("Element %d found at position %d\n",value,i+1);
        flag=1;
        break;
        }
    }

    if(flag==0)
    {
        size++;

        arr=(int *)realloc(arr,(size * sizeof(int)));

        for(i=size-1;i>=1;i--)
        {

            *(arr+i) = *(arr+i-1);
        }

         *(arr+0)=value;
         display(arr,size);
    }

}

//function to perform search operation
void searchKey(int *arr)
{
     int flag=0;
    printf("Enter the value of search element : ");
    scanf("%d",&value);

    for(i=0;i<size;i++)
    {
        if(*(arr+i)==value)
        {
            printf("Element %d found at position %d\n",value,i+1);
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("Element %d absent",value);
    }


}

//function to display element at given position
void searchPos(int *arr)
{

    printf("Enter Search Position");
    scanf("%d",&indx);
    int flag=0;
    for(i=0;i<size;i++)
    {
        if(i+1==indx)
        {
            printf("Array element at position %d is %d\n",indx,*(arr+i));
            flag=1;
        }
        
    }
       if(flag==0)
        printf("Invalid Index\n");
}


//search and delet key if present
void deleteKey(int *arr)
{
 int flag=0;
printf("Enter the value of search element : ");
scanf("%d",&value);
for(i=0;i<size;i++)
{
if(*(arr+i)==value)
{
    indx=i+1;
    flag=1;
    break;
}
}
if(flag==0)
{
    printf("Element absent\n");
}
else
{
    if(indx<=size)
    {
    for(i=indx-1;i<size;i++)
    {

    *(arr+i)=*(arr+i+1);
    }
    size-=1;
    display(arr,size);
    }
}

}


//reverse given array
void arrRev(int * arr)
{   int *rev,j=0;
    rev=(int *)malloc(size*sizeof(int));

    for(i=size-1;i>=0;i--)
    {
        *(rev+j) = *(arr+i);
        j++;   
    }
   display(rev,size);
}


//fuction to insert element in order
void insertOrder(int *arr)
{
    int j,temp;
    size++;
    arr=(int *)realloc(arr,(size * sizeof(int)));
    printf("Enter insertion element :");
    scanf("%d",&value);
    
     for(i=size-1;i>=1;i--)
    {

    *(arr+i)=*(arr+i-1);
    }

    *(arr+0)=value;

    
    for(i=0;i<size;i++)
    {
        for(j=0;j<(size-i-1);j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
    display(arr,size);

    
}

/* ****************************************************************************************************************** */

// Functions for static memory allocations

//function to read array
void stread(int a[100],int size)
{
printf("Enter array elements\n");
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
}

//function to display array
void stdisplay(int a[100], int size)
{
printf("Your new array is :");
for(i=0;i<size;i++)
{
printf("\t %d",a[i]);
}
}

//function to insert element in array
void stinsertPos(int a[100])
{

  printf("Enter value of element and position : ");
scanf("%d%d",&value,&indx);
if(indx>0 && indx<=size)
{ size+=1;
for(i=size-1;i>=indx;i--)
{
a[i]=a[i-1];
}

a[indx-1]=value;


stdisplay(a,size);
}
else
{
printf("Invalid Index");
}

}

//function to perform deletion
void stdeletePos(int a[100])
{

printf("Enter the value of position : ");
scanf("%d",&indx);
if(indx<=size)
{
for(i=indx-1;i<size;i++)
{

a[i]=a[i+1];
}
size-=1;
display(a,size);
}
else
{
printf("Invalid Index");
}

}


//function to search element and insert if element absent
void stinsertKey(int a[100])
{
    int flag=0;
    printf("Enter the value of search element : ");
    scanf("%d",&value);
    for(i=0;i<size;i++)
    {
        if(a[i]==value)
        {
        printf("Element %d found at position %d\n",value,i+1);
        flag=1;
        break;
        }
    }

    if(flag==0)
    {
        size++;
        for(i=size-1;i>=1;i--)
        {
            a[i] = a[i-1];
        }
         a[0]=value;
         display(a,size);
    }

}

//function to perform search operation
void stsearchKey(int a[100])
{
     int flag=0;
    printf("Enter the value of search element : ");
    scanf("%d",&value);

    for(i=0;i<size;i++)
    {
        if(a[i]==value)
        {
            printf("Element %d found at position %d\n",value,i+1);
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("Element %d absent",value);
    }


}

//function to display element at given position
void stsearchPos(int a[100])
{

    printf("Enter Search Position");
    scanf("%d",&indx);
    int flag=0;
    for(i=0;i<size;i++)
    {
        if(i+1==indx)
        {
            printf("Array element at position %d is %d\n",indx,a[i]);
            flag=1;
        }
        
    }
       if(flag==0)
        printf("Invalid Index\n");
}


//search and delet key if present
void stdeleteKey(int a[100])
{
 int flag=0;
printf("Enter the value of search element : ");
scanf("%d",&value);
for(i=0;i<size;i++)
{
if(a[i]==value)
{
    indx=i+1;
    flag=1;
    break;
}
}
if(flag==0)
{
    printf("Element absent\n");
}
else
{
    if(indx<=size)
    {
    for(i=indx-1;i<size;i++)
    {

    a[i]=a[i+1];
    }
    size-=1;
    display(a,size);
    }
}

}


//reverse given array
void starrRev(int a[100])
{   int j=0;
    
    for(i=size-1;i>=0;i--)
    {
        rev[j] = a[i];
        j++;   
    }
   display(rev,size);
}


//fuction to insert element in order
void stinsertOrder(int a[100])
{   
    int j,temp;
    size++;
    printf("Enter value of new element : ");
    scanf("%d",&value);
    a[size-1]=value;
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<(size-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }  
    display(a,size);  
    
}
