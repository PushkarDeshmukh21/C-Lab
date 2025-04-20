#include<stdio.h>
#include<stdlib.h>

#define MAX 100
struct Queue
{
   int items[MAX];
   int f, r;
};

struct queue
{
   int *items;
   int front, rear;
};


typedef struct Queue QUE;
void InsertR( QUE *);
void DeleteF(QUE *);
void InsertF( QUE *);
void DeleteR(QUE *);
void Disp(QUE *);

typedef struct queue que;
void DInsertR( que *);
void DDeleteF(que *);
void DInsertF( que *);
void DDeleteR(que *);
void DDisp(que *);

 int size;

int main()
{
  int ch,choice;
  QUE Q;
  que q;
  q.front=0; q.rear= -1;
  Q.f= 0; Q.r = -1;
 
  printf("Enter size of queue: ");
  scanf("%d",&size);
  q.items=(int *)malloc(size*sizeof(int));

  for(;;)
  {
      printf("\n1.DMA\n2.SMA\n3.Exit\nEnter Choice: ");
      scanf("%d",&choice);
    switch(choice)
    {
        case 1:
          printf("enter choice:\n1:InsertRear\n2:DeleteFront\n3:InsertFront\n4:DeleteRear\n5:Display\n");
          scanf("%d", &ch);
          switch(ch)
          {
            case 1: DInsertR(&q); DDisp(&q); break;
            case 2:  DDeleteF(&q); DDisp(&q); break;
            case 3: DInsertF(&q); DDisp(&q); break;
            case 4:  DDeleteR(&q); DDisp(&q); break;
            default:printf("Invalid");
          }
          break;

        case 2:
          printf("enter choice:\n1:InsertRear\n2:DeleteFront\n3:InsertFront\n4:DeleteRear\n5:Display\n");
          scanf("%d", &ch);
          switch(ch)
          {
            case 1: InsertR(&Q); Disp(&Q); break;
            case 2:  DeleteF(&Q); Disp(&Q); break;
            case 3: InsertF(&Q); Disp(&Q); break;
            case 4:  DeleteR(&Q); Disp(&Q); break;
            default:  printf("Invalid");
          }
          break;

        case 3:exit(0);
        default:printf("Invalid Choice!");
    }
   
  }
  return 0;
}


void InsertR(QUE *Q)
{
  int item;
  if(Q->r==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
 // Q->r++;
  Q->items[++Q->r] = item;
 }
 void DeleteF(QUE *Q)
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

void InsertF(QUE *Q)
{
  int item;
  if(Q->f==0 && Q->r!=-1)
  {
    printf("Front Insertion not possible,No rooms at the front\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  if(Q->f==0 && Q->r==-1)
  {
 // Q->r++;
  Q->items[++Q->r] = item;
  return;
 }
  Q->items[--Q->f] = item;
 }

 void DeleteR(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",Q->items[Q->r]);
   Q->r--;
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }





 void DInsertR(que *q)
{
  int item;
  if(q->rear==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item: ");
  scanf("%d",&item);
  q->rear++;
  *(q->items+q->rear)= item;
 }
 void DDeleteF(que *q)
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
    for(i=q->front;i<=q->rear;i++)
    {
      printf("%d ",*(q->items+i));
    }
 }

void DInsertF(que *q)
{
  int item;
  if(q->front==0 && q->rear!=-1)
  {
    printf("Front Insertion not possible,No rooms at the front\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  if(q->front==0 && q->rear==-1)
  {
  q->rear++;
  *(q->items+q->rear) = item;
  return;
 }
  q->front--;
  *(q->items+q->front) = item;
 }

 void DDeleteR(que *q)
 {
   if(q->front>q->rear)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",*(q->items+q->rear));
   q->rear--;
   if(q->front>q->rear)
   {
     q->front=0; q->rear=-1;
   }
 }