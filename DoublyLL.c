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
    printf("Enter 1 to input node and 0 to continue: ");
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
        printf("Ente 1 or 0: ");
        scanf("%d",&ch);
    }    
    
    return head;
}

NODE *display(NODE *head)
{
    NODE *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is Empty!! ");
    }
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->rptr;
    }
}

NODE *insertBeg(NODE *head)
{
    if(head==NULL)
    {
        head=CreateNode();
    }
    else
    {
        newnode=CreateNode();
        
        newnode->rptr=head;
        head->lptr=newnode;
        head=newnode;
    }
    return head;
}

NODE *insertEnd(NODE *head)
{
    if(head==NULL)
    {
        head=CreateNode();
    }
    else
    {
        newnode=CreateNode();
        tail->rptr=newnode;
        newnode->lptr=tail;
        tail=newnode;
    }
    return head;
}

NODE *deleteBeg(NODE *head)
{
    if(head==NULL)
    {
        printf("Empty list ");
    }
    else
    {
        NODE *temp=head;
        head=head->rptr;
        head->lptr=NULL;
        free(temp);

    }
    return head;
}

NODE *deleteEnd(NODE *head)
{    NODE *temp;
    if(head==NULL)
    {
        printf("Empty list");
        return head;
    }
    else if(head->rptr==NULL)
    {
        head=NULL;
        free(tail);
        return head;
    }
    else
    {
        temp=tail;
    tail=temp->lptr;
    tail->rptr=NULL;
    
    free(temp);  
     return head;  
    }
   
}

NODE *insertPos(NODE *head)
{
    if(head==NULL)
    {
        head=CreateNode();

    }
    else if (head->rptr==NULL)
    {
       head=insertBeg(head);
    }
    
    else
    {
        int pos;
        NODE *temp=head;
        printf("Enter insertion position:");
        scanf("%d",&pos);
        
        int i=1;
        
        while(i<pos-1)
        {
            temp=temp->rptr;
            i++;
        }
        if(temp->rptr==NULL)
        {
            head=insertEnd(head);
        }
        else
        {
         newnode=CreateNode();
        newnode->lptr=temp;
        newnode->rptr=temp->rptr;
        temp->rptr=newnode;
        newnode->rptr->lptr=newnode;
        temp=NULL;
        }
    }
    return head;
}

NODE *deletePos()
{   NODE *temp;
    if(head==NULL)
    {
        printf("Empty list!!");
        return head;
    }
        
    else
    {
        int pos,i=1;
        printf("Enter deletion position: ");
        scanf("%d",&pos);
        while(i<pos)
        {
            temp=temp->rptr;
            i++;

        }
        if(head->rptr=NULL )
        {
            head=deleteEnd(head);
            return head;
        }
        if(temp->rptr=NULL)
        {
            head=deleteEnd(head);
            return head;
        }
        
        temp->lptr->rptr=temp->rptr;
        temp->rptr->lptr=temp->lptr;
        free(temp);
        return head;
    }

}

NODE *deleteKey()
{
    
        int key,flag=0;
        int i=0;
        printf("Enter Search element : ");
        scanf("%d",&key);
       NODE *temp=head;
        while(temp!=NULL)
        {
                if(temp->data==key)
        {
                printf("Element %d found at %d position\n",key,i+1);
                flag=1;
                break;
        }
                temp=temp->rptr;
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
                temp=temp->rptr;
                j++;
                }
                if(temp->rptr==NULL){
                deleteEnd(head);}
                NODE *nextnode=temp->rptr;
                temp->rptr=nextnode->rptr;
                free(nextnode);
                
                }
                    
        }
        else
        printf("element absent\n");
        return head;

}

NODE *SearchKey(NODE *head)
{
    if(head==NULL)
    {
        printf("Empty list!!");
        return head;
    }
    else
    {
        int flag=0,key,i=1;
        printf("Enter search key: ");
        scanf("%d",&key);
        NODE *temp=head;
        while(temp!=0)
        {
            if(temp->data==key)
            {
                printf("Element %d has been found in the series at position %d",key,i);
                flag=1;
            }
            temp=temp->rptr;
            i++;
        }
        if(flag==0)
        {
            printf("Element %d is absent",key);
        }
        
    }

}

NODE *insertOrder()
{

}

NODE *revLL(NODE *head)
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

NODE *copyLL(NODE *head)
{
    NODE *temp=head;
    NODE *head1=NULL;
    NODE *tail1;
    while(temp!=0)
    {   
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=temp->data;
        newnode->lptr=NULL;
        newnode->rptr=NULL;
        if(head1==NULL)
        {
           tail1=newnode;
           head1=newnode;
             
 
        }
        else
        {
            tail1->rptr=newnode;
            newnode->lptr=tail1;
            tail1=newnode;
            
        }
       temp=temp->rptr;
    }
    return head1;

}

void main()
{
    int choice,n;

printf("Enter total number of nodes in linked list");
scanf("%d",&n);

while(1){
printf("\n1.Create Linked list\n2.Insertion at beginning\n3.Insertion at end\n4.Deletion at beginning\n5.Deletion at end\n6.Insertion at position\n7.deletion at position\n8.Search by key\n9.Deletion by key\n10.Insertion by order\n11.Reverse Linked list\n12.Copy linked list\n");
printf("Enter your choice :");
scanf("%d",&choice);

switch(choice)
{
case 1:head=CreateDLL(n);

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
case 8: SearchKey(head);
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

