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

struct node *print(struct node *head)
{
    printf("Required linked list is :");
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
    *print(head);
}

