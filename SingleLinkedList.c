#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}node;

 node *createNode();
 node *createLL(int );
node *insertBeg(node *);
node *insertEnd(node *);
node *deleteBeg(node *);
node *deleteEnd(node *);
node *insertPos(node*);
node *deletePos(node *);
node *insertKey(node *);
node*deleteKey(node *);
node *insertOrder(node *);
node *revLL(node *);
node *copyLL(node *);
void display(node *);
 node *newnode,*head,*temp,*nextnode;
int count,i;


void main()

{
int choice,n;

printf("Enter total number of nodes in linked list");
scanf("%d",&n);

while(1){
printf("\n1.Create Linked list\n2.Insertion at beginning\n3.Insertion at end\n4.Deletion at beginning\n5.Deletion at end\n6.Insertion at position\n7.deletion at position\n8.Insertion by key\n9.Deletion by key\n10.Insertion by order\n11.Reverse Linked list\n12.Copy linked list\n");
printf("Enter your choice :");
scanf("%d",&choice);

switch(choice)
{
case 1:head=createLL(n);
        display(head);
        break;
case 2: head=insertBeg(head);
        display(head);
        break;
case 3: head=insertEnd(head);
        display(head);
        break;
case 4: head=deleteBeg(head);
        display(head);
        break;
case 5: head=deleteEnd(head);
        display(head);
        break;
case 6:head=insertPos(head);
        display(head);
        break;
case 7: head=deletePos(head);
        display(head);
        break;
case 8: head=insertKey(head);
        display(head);
        break;
case 9:head=deleteKey(head);
        display(head);
        break;
case 10:head=insertOrder(head);
        display(head);
        break;
case 11:head=revLL(head);
        display(head);
        break;
case 12:head=copyLL(head);
        display(head);
        break;
default:exit(0);
}

}
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
count =0;
printf("Your linked list is :");
while(temp!=NULL)
{
printf("\t%d",temp->data);
temp=temp->next;
count++;
}
printf("\n");
}

node *insertBeg(node *head)
{
createNode();
newnode->next=head;
head=newnode;

return head;
}

node *insertEnd(node *head)
{
createNode();
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;

return head;
}

node *deleteBeg(node *head)
{ if(head==NULL)
{
printf("Linked List Empty......\n Create a Linked list first\n");
}
else if(head->next==NULL)
{temp=head;
head=NULL;
free(temp);

}
else
{head=temp;
 head=temp->next;
 temp->next=NULL;
 free(temp);
}

return head;
}

node *deleteEnd(node *head)
{
if(head==NULL)
{
printf("Linked List Empty......\n Create a Linked list first\n");
}
else if(head->next==NULL)
{temp=head;
head=NULL;
free(temp);

}
else
{
temp=head;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
node *nextnode=temp->next;
temp->next=NULL;
free(nextnode);

}
return head;
}

node *insertPos(node *head)
{
int pos;
i=1;
createNode();
temp=head;
printf("Enter insertion position :");
scanf("%d",&pos);
if(head==NULL)
{
        head=createNode();
}
else{
while(i<pos-1)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
}

return head;
}

node *deletePos(node *head)
{
int pos;
i=1;
temp=head;
printf("Enter deletion position :");
scanf("%d",&pos);
while( i<pos-1)
{
temp=temp->next;
i++;
}
nextnode=temp->next;
temp->next=nextnode->next;
free(nextnode);

return head;
}

node *insertKey(node *head)
{ int key,flag=0;
i=0;
printf("Enter Search element : ");
scanf("%d",&key);
temp=head;
while(temp!=NULL)
{
if(temp->data==key)
{
printf("Element %d found at %d position",key,i+1);
flag=1;
break;
}
i++;
temp=temp->next;
}

if(flag==0)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=key;
newnode->next=head;
head=newnode;

return head;
}
}

node *deleteKey(node *head)
{
        int key,flag=0;
        i=0;
        printf("Enter Search element : ");
        scanf("%d",&key);
        temp=head;
        while(temp!=NULL)
        {
                if(temp->data==key)
        {
                printf("Element %d found at %d position\n",key,i+1);
                flag=1;
                break;
        }
                temp=temp->next;
                i++;
        }

        if(flag==1)
        {
                if(head==NULL)
                printf("Linked list empty");
                else if(head->data==key){
                deleteBeg(head);
                }
        
                else{
                int j=1;
                temp=head;

                 while( j<i){
                temp=temp->next;
                j++;
                }
                if(temp->next==NULL){
                deleteEnd(head);}
                nextnode=temp->next;
                temp->next=nextnode->next;
                free(nextnode);
                
                }
                    
        }
        else
        printf("element absent\n");
        return head;
}

node *copyLL(node *head)
{
    if(head==NULL)
    {
        return NULL;

    }
    else{
        node *Nnode=(node *)malloc(sizeof(node));
        Nnode->data=head->data;
        Nnode->next=copyLL(head->next);
        return Nnode;
    }
}

node *revLL(node *head)
{
        node *prevnode,*currentNode,*nextnode;
        prevnode=NULL;

        currentNode=nextnode=head;
        while(nextnode!=NULL)
        {
                nextnode=nextnode->next;
                currentNode->next=prevnode;
                prevnode=currentNode;
                currentNode=nextnode;
        }
        head=prevnode;
        
}

node *insertOrder(node *head)
{
        if(head==NULL)
        {
                head=createNode();
                return head;
        }
        else{
                node *prev=head;
                temp=head;
                newnode=createNode();
                if(newnode->data<head->data)
                {
                        newnode->next=head;
                        head=newnode;
                        return head;
                }
                temp=head->next;
                while (temp!=0 && prev->next==temp)
                {
                        if(newnode->data<temp->data)
                        {
                                newnode->next=temp;
                                prev->next=newnode;
                        }
                        temp=temp->next;
                        prev=prev->next;
                       
                }
                return head;
                
        }
        

}