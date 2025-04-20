#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}node;
int n;
node *newnode,*head,*temp,*nextnode;

 node *createNode()
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter the data for new node  :");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}


void display(node *temp)
{

printf("Your linked list is :");
while(temp!=NULL)
{
printf("\t%d",temp->data);
temp=temp->next;

}
printf("\n");
}

node *createLL(int n)
{
head=NULL;
for(int i=0;i<n;i++)
{
*createNode(i);
if(head==NULL)
{
head=temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
}

return head;
}

node *Sort(node *head,int n)
{
    temp=head;
    
    int i,j,swap;
   while(temp->next!=NULL){
    nextnode=temp->next;
        while(nextnode!=NULL){
            if(temp->data>nextnode->data)
            {
                swap=nextnode->data;
                nextnode->data=temp->data;
                temp->data=swap;
            }
           
            nextnode=nextnode->next;
        }
         temp=temp->next;
    }
    

    
    printf("For the Ordered Insertion:\n");
    newnode=createNode();

    temp=head;
    nextnode=temp->next;
    if(head->data>newnode->data){
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(nextnode!=NULL && temp->next==nextnode){
        if(newnode->data<nextnode->data){
            newnode->next=nextnode;
            temp->next=newnode;
        }
        nextnode=nextnode->next;
        temp=temp->next;
       
    }

    return head;

}

void main()
{
    printf("Enter the total number of node: ");
    scanf("%d",&n);
    printf("\n");
    head=createLL(n);
    display(head);
    printf("\n");
    head=Sort(head,n);
    display(head);
    
}