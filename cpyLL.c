#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}node;
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
createNode(i);
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
display(head);
return head;
}

 



node *cpy(node *head)
{
    if(head==NULL)
    {
        return NULL;

    }
    else{
        node *Nnode=(node *)malloc(sizeof(node));
        Nnode->data=head->data;
        Nnode->next=cpy(head->next);
        return Nnode;
    }
}

void main()
{   int n;
    printf("Enter total number of nodes in linked list");
scanf("%d",&n);
createLL(n);

node *head1=cpy(head);
display(head1);
}
