#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *lptr;
    struct node *rptr;

}NODE;
NODE *head,*tail,*newnode;

NODE *CreateNode()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("Enter data for new node:");
    scanf("%d",&newnode->data);
    newnode->lptr=NULL;
    newnode->rptr=NULL;
    return newnode;
}

NODE *CreateDLL()
{   int ch;
    printf("1/0: ");
    scanf("%d",&ch);
    head=NULL;
    while(ch)
    {
        newnode=CreateNode();
    

        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            
        }
        else
        {
            tail->rptr=newnode;
            newnode->lptr=tail;
            tail=newnode;
            
        }
        printf("1/0");
        scanf("%d",&ch);
    }    
    return head;
}

NODE *display(NODE *head)
{
    NODE *temp;
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->rptr;
    }
}

NODE *Reverse(NODE *head)
{
    NODE *nextnode,*current;
    if(head==NULL)
    {
        head=CreateNode();
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
    
        return head;
}

NODE *Copy(NODE *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else{
        
    }
}

void main()
{
    int ch;
    tail=NULL;
    head=CreateDLL();
    display(head);
    head=Reverse(head);
    display(head);
    
}