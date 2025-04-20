#include<stdio.h>
#include<stdlib.h>

typedef struct stack{   
    int top;
    int max_size;
    int *array;
}stack;

typedef struct Stack{
    int max_size;
    int top;
    int array[100];
}Stack;

//stack operations using DMA
stack* stackPush(stack*);      
stack* stackPop(stack*);      
void   stackPeek(stack*);
void   displayStack(stack*);

//Stack operations using SMA
Stack*pushStack(Stack*);
Stack*popStack(Stack*);
void peekStack(Stack*);
void stackDisplay(Stack*);

int choice,ch,i;

int main()
{
    stack*s;
    s = (stack*)malloc(sizeof(stack));  //for Stack implementation using DMA
    
    Stack*q;
    q = (Stack*)malloc(sizeof(Stack));  //for Stack implementation using SMA
    
    printf("\nEnter the maximum number of elements for the stack using DMA:\t");
    scanf("%d",&s->max_size);
    s->array = (int*)malloc((s->max_size)*sizeof(int));   //Dynamic allocation of array to int*array
    s->top = -1;
    
    printf("\nEnter the maximum number of elements for the stack using SMA:\t");
    scanf("%d",&q->max_size);   //already a[100] is there as a structure member
    q->top = -1;
    
    while(1)
    {
        printf("\n1.Stacks using Dyanamic memory allocation\n2.Stacks using Static memory allocation\n3.Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
            printf("\nEnter your choice:");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: s = stackPush(s); break;
                case 2: s = stackPop(s);  break;
                case 3: stackPeek(s);  break;
                case 4: displayStack(s); break;
                default: printf("\nInvalid choice!!\n");
            }
            break;

            case 2:
            printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
            printf("\nEnter your choice:");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: q=pushStack(q);break;
                case 2: q=popStack(q);break;
                case 3: peekStack(q);break;
                case 4: stackDisplay(q);break;
                default: printf("\nInvalid choice!!\n");
            }
            break;
            case 3: exit(0);
            default: printf("Invalid Choice !!");
            }
    }
    
    return 0;
}

stack* stackPush(stack*s)
{
    s->top++;
    
    if(s->top >= s->max_size)
    {
        s->top = s->max_size - 1;
        printf("\nStack Overflow!!");
        return s;
    }
    
    else
    {
        printf("\nEnter the data:\t");
        scanf("%d",&s->array[s->top]);
        
        printf("\n%d is now at the top of stack",s->array[s->top]);
        
        return s;
    }
}

stack* stackPop(stack*s)
{
    s->top--;
    if(s->top < -1)
    {
        s->top = -1;
        printf("\nStack Underflow !!");
    }
    
    else
    {
        printf("\nElement %d popped...\n",s->array[s->top+1]);
    }
    
    return s;
}

void stackPeek(stack*s)
{
    if(s->top == -1)
    {
        printf("\nStack is empty\n");
    }
    
    else
    {
        printf("\n%d is the topmost element\n",s->array[s->top]);
    }
}

void   displayStack(stack*s)
{
    i=0;
    if(s->top == -1)
    {
        printf("\nStack is empty...\n");
    }
    
    else
    {
        do{
            printf("%d\n",s->array[i]);
            i++;
        }while(i < s->top);
    }
}

Stack* pushStack(Stack*q)
{
    q->top++;
    if(q->top >= q->max_size)
    {
        q->top--;
        printf("\nStack Overflow !!\n");
    }
    
    else
    {
        printf("\nEnter the data:\t");
        scanf("%d",&q->array[q->top]);
        printf("\nElement %d pushed on top of stack...\n",q->array[q->top]);
    }
    
    return q;
}

Stack* popStack(Stack*q)
{
    q->top--;
    if(q->top < -1)
    {
        q->top = -1;
        printf("\nStack Underflow !!");
    }
    
    else
    {
        printf("\nElement %d popped...\n",q->array[q->top+1]);
    }
    
    return q;
}


void peekStack(Stack*q) 
{
    if(q->top == -1)
    {
        printf("\nStack is empty\n");
    }
    
    else
    {
        printf("\n%d is the topmost element\n",q->array[q->top]);
    }
}

void   stackDisplay(Stack*q)
{
    i=0;
    if(q->top == -1)
    {
        printf("\nStack is empty...\n");
    }
    
    else
    {
        do{
            printf("%d\n",q->array[i]);
            i++;
        }while(i < q->top);
    }
}



 