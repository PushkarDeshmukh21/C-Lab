#include<stdio.h>
#include<stdlib.h>
//#define size 6
int size;
struct Queue
{
   int *items;
   int f, r;
};

typedef struct Queue QUE;
void Insert( QUE *);
void Delete(QUE *);
void Disp(QUE *);


int main()
{
  int ch;
  QUE Q; // struct QUEUE Q
  Q.f= 0; Q.r = -1;
  
  printf("Enter Q Size:\n");
  scanf("%d",&size);
  Q.items = (int *) malloc(size * sizeof(int));
  for(;;)
  {
    printf("enter choice:\n1:Insert\n2:Delete\n3:Display\n");
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: Insert(&Q); Disp(&Q); break;
       case 2:  Delete(&Q); Disp(&Q); break;
       case 3:   Disp(&Q); break;
       default:  exit(0);
    }
    }
    return 0;
  }
void Insert(QUE *Q)
{
  int item;
  if(Q->r==size-1)
  {
    printf("Queue Full Reallocating...\n");
    //Q->items = (int *) realloc(Q->items, size*2);
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  Q->r++;
  *(Q->items+ Q->r) = item;
 }
 void Delete(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",*(Q->items+Q->f));
   Q->f++;
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }                 //   -  -   -   -  50  60   f = 4  r = 5

 void Disp(QUE *Q)
 {  int i;
     if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
    for(i=Q->f; i<=Q->r; i++)

      printf("%d  ", *(Q->items+i));
 }


