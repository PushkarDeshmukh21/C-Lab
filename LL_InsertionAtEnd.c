/*C program to perform linked list operations*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int );
struct node *print(struct node *);
struct node *createLL(int );
void insertEnd();
struct node *newnode,*head,*temp;

struct node *createLL(int n)
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

struct node *createNode(int i)
{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d :\n",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        return newnode;
}

void insertEnd()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data of Insertion node :\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

struct node *print(struct node *head)
{
   
    temp =head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int n;
    printf("Enter the number of elemenst of linked list :");
    scanf("%d",&n);

    *createLL(n);
     printf("Original linked list is :");
    *print(head);
    
    insertEnd();
    printf("Linked List after Insertion :\n");
    *print(head);
}

