#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *lptr;
    struct node *rptr;
}node;
node *head,*tail,*newnode,*temp;

void reverse();
void main()
{
    int ch;
    printf("Enter 1 to add node to linked list and 0 to continue:");
    scanf("%d",&ch);
    while(ch)
    {
            node *newnode=(node*)malloc(sizeof(node));
            printf("Enter the data for newnode: ");
            scanf("%d",&newnode->data);
            newnode->lptr=newnode->rptr=NULL;
            if(head==NULL)
            {
                head=tail=newnode;
            }
            else
            {
                tail->lptr=newnode;
                newnode->rptr=tail;
                tail=newnode;
                
            }
            printf("Enter 1 to add node to linked list and 0 to continue:");
            scanf("%d",&ch);
            
    }
     
    reverse();
    

}


void reverse()
{
    node *nextnode,*current;
    if(head==NULL)
    {
        node *newnode=(node*)malloc(sizeof(node));
    printf("Enter the data for newnode: ");
    scanf("%d",&newnode->data);
    newnode->lptr=newnode->rptr=NULL;
        head=newnode;
        tail=head;
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            nextnode=current->rptr;
            current->rptr=current->lptr;
            current->lptr=nextnode;
            current=nextnode;   
        }
        current=head;
        head=tail;
        tail=current;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->rptr;
    }

}