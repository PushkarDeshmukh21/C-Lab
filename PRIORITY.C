#include<stdio.h>
#include<stdlib.h>

#define MAX 6
struct Queue
{
   int items[MAX];
   int f, r;
};
struct queue{
  int *items;
  int front,rear;
};

typedef struct Queue QUE;
void Insert( QUE *);
void Delete(QUE *);
void Disp(QUE *);

typedef struct queue que;
void DInsert( que *);
void DDelete(que *);
void DDisp(que *);
int size;

int main()
{
  int ch,choice;
  QUE Q;
  que q;
  printf("Enter size of queue: ");
  scanf("%d",&size);
  q.items=(int *)malloc(size*sizeof(int));
  
  q.front=0;q.rear=-1;
  Q.f= 0; Q.r = -1;
  
  for(;;)
  {
    printf("\n1.SMA\n2.DMA\n3.exit\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      
          printf("\n1:Insert\n2:Delete\n3:Display\nEnter choice: ");
          scanf("%d", &ch);
          switch(ch)
          {
            case 1: Insert(&Q); Disp(&Q); break;
            case 2:  Delete(&Q); Disp(&Q); break;
            case 3:   Disp(&Q); break;
            default:  exit(0);
          }break;
     case 2:
            
            printf("\n1:Insert\n2:Delete\n3:Display\nenter choice: ");
      scanf("%d", &ch);
      switch(ch)
      {
        case 1: DInsert(&q); DDisp(&q); break;
        case 2:  DDelete(&q); DDisp(&q); break;
        case 3:   DDisp(&q); break;
        default:  exit(0);
      }
      break;
      case 3: exit(0);
      default: printf("Invalid choice: ");
     }
  }
return 0;
}
void Insert(QUE *Q) // Inserting in Ascending order
{
  int item, j;
  if(Q->r==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
 // Q->r++;
  j = Q->r;
  while(j>=0 && Q->items[j] > item)
  {

    Q->items[j+1] = Q->items[j];
    j--;
 }
 Q->items[++j] = item;
 Q->r++;
 }
 void Delete(QUE *Q)   // Deleting front item which has the highest priority
 {
   if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",Q->items[Q->f++]);
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }                 //       30  40  50   f = 2  r = 4  f = 0

 void Disp(QUE *Q)
 {  int i;
     if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
    for(i=Q->f; i<=Q->r; i++)

      printf("%d  ", Q->items[i]);
 }




void DInsert(que *q) // Inserting in Ascending order
{
  int item, j;
  if(q->rear==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
 // Q->r++;
  j = q->rear;
  while(j>=0 && *(q->items+j) > item)
  {

    *(q->items+j+1) = *(q->items+j);
    j--;
 }
 j++;
 *(q->items+j) = item;
 q->rear++;
 }
 void DDelete(que *q)   // Deleting front item which has the highest priority
 {
   if(q->front>q->rear)
   {
      printf("Queu Empty\n");
      return;
   }
   
   printf("deleted:%d\n",*(q->items+q->front));
   q->front++;
   if(q->front>q->rear)
   {
     q->front=0; q->rear=-1;
   }
 }                 //       30  40  50   f = 2  r = 4  f = 0

 void DDisp(que *q)
 {  int i;
     if(q->front>q->rear)
   {
      printf("Queu Empty\n");
      return;
   }
    for(i=q->front; i<=q->rear; i++)

      printf("%d  ", *(q->items+i));
 }
