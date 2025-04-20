#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
  };

 struct ListNode* createNode(){
     struct ListNode* new;
     new=(struct ListNode *)malloc(sizeof(struct ListNode));
     new->val=0;
     new->next=NULL;
     return new;
 }

 struct ListNode* Rev(struct ListNode* head)
{
    if(head==NULL){
        return NULL;
    }
    struct ListNode *prevnode,*currentNode,*nextnode;
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
        return head;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* temp1,*temp2,*temp;
    l1=Rev(l1);
    l2=Rev(l2);
   temp1=l1;temp2=l2;
   int N1=0,N2=0;
   while(temp1!=NULL || temp2!=NULL)
   {
       if(temp1!=NULL){
           N1=N1+(temp1->val)*10;
           temp1=temp1->next;
       }
       if(temp2!=NULL){
           N2=N2+(temp2->val)*10;
           temp2=temp2->next;
       }
   }

   int sum=N1+N2;
   struct ListNode *add;
   while(sum!=0){
   if(add==NULL){
      temp=add=createNode();
      temp->val=sum%10;
      sum=sum/10;
   }
   else{
       temp->next=createNode();
       temp=temp->next;
       temp->val=sum%10;
       sum=sum/10;
   }
   }
return add;

}

int main(){
    struct ListNode* add,*temp;
    struct ListNode* l1=NULL,*l2=NULL;
    int n1,n2;
    printf("Enter node in linked list 1 and linked list 2 respectively: ");
    scanf("%d%d",&n1,&n2);
    for(int i=0;i<n1;i++){
        if(l1==NULL){
            temp=l1=createNode();
            printf("Enter data for new node: ");
            scanf("%d",&temp->val);
        }
        else{
            temp->next=createNode();
            temp=temp->next;
            printf("Enter data of new node: ");
            scanf("%d",&temp->val);
        }
    }

    for(int i=0;i<n2;i++){
        if(l2==NULL){
            temp=l2=createNode();
            printf("Enter data for new node: ");
            scanf("%d",&temp->val);
        }
        else{
            temp->next=createNode();
            temp=temp->next;
            printf("Enter data of new node: ");
            scanf("%d",&temp->val);
        }
    }

    temp=add=addTwoNumbers(l1,l2);
    while(temp!=NULL){
        printf("%d\t",temp->val);
        temp=temp->next;
    }
    return 0;
}

