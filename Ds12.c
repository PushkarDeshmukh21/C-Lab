/*  C-program to implement binary search tree and traversal techniques */

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *left,*right;
}node;

node* createNode(node*,int);
int   searchNode(node*,int);
void  inOrder(node*);
void  postOrder(node*);
void  preOrder(node*);
void  whoIsTheParent(node*,node*,int);
void  nodeCount(node*,int*);
int   heightOfTree(node*);

node* inPost(node*); //to find inorder successor
node* delete(node*,int);


int main()
{
    int i, data, n; int*count = &n;
    node*root = NULL; node*parent;
    
    printf("\nEnter the number of nodes for Binary search tree:\t"); scanf("%d",&n);
    for(i =0; i<n; i++)
    {
        printf("\nNode %d:\t",(i + 1)); scanf("%d",&data);
        if(searchNode(root,data))
          {
            printf("\n%d already exists in the present BST...\n",data);
            i--;
          }
          
        else
        root = createNode(root,data);
    }

    for(;;)
    {
        printf("\n1.Insertion in BST\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Count the number of nodes\n6.Search a node(along with it's parent details)\n7.Height of tree\n8.Delete a node\n9.Exit\nEnter your choice:\t\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:{
                    printf("\nEnter the data:\t"); scanf("%d",&data);
                    if(searchNode(root,data))
                      {
                        printf("\n%d already exists in the present BST...\n",data);
                        break;
                      }
                    else
                    root = createNode(root,data);
                   } break;
            
            case 2: {
                        if(root == NULL)
                        printf("\nTree is empty...\n");
                        inOrder(root); printf("\n");
                    }
                    break;
                    
            case 3: {
                        if(root == NULL)
                        printf("\nTree is empty...\n");
                        preOrder(root); printf("\n");
                    }
                    break;
                    
            case 4: {
                        if(root == NULL)
                        printf("\nTree is empty...\n");
                        postOrder(root); printf("\n");
                    }
                    break;
                    
            case 5: {
                        *count = 0;
                        nodeCount(root,count);
                        printf("\nNumber of nodes: %d\n",*count);
                    } 
                    break;
                    
            case 6: {
                        printf("\nEnter the data: "); scanf("%d",&data);
                        if(searchNode(root,data))
                        {
                            parent = NULL;
                            whoIsTheParent(root,parent,data);
                        }
                        else
                        {
                            printf("\n%d does not exist in this tree\n",data);    
                        }
                    
                    } 
                    break;
                    
            case 7: {
                        *count = 0;
                        n = heightOfTree(root);
                        printf("\nHeight of the tree is : %d",n); 
                    }   
                    break;
                    
            case 8: {
                        printf("\nEnter the data: "); scanf("%d",&data);
                        if(searchNode(root,data))
                        {
                            root = delete(root,data);
                        }
                        else
                        {
                            printf("\n%d does not exist in this tree\n",data);    
                        }
                    }   
                    break;
                    
            case 9: exit(0);        
                    
            default: printf("\nInvalid choice...\n");
        }
    }
    return 0;
}

node*createNode(node*root, int data)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    
    else if(data < root->data)
    {
        root->left = createNode(root->left, data);
    }
    
    else
    {
        root->right = createNode(root->right,data);
    }
    
    return root;
}

int searchNode(node*root,int data)
{
    if(root == NULL)
    return 0;
    
    else if(data < root->data)
    searchNode(root->left,data);
    
    else if(data > root->data)
    searchNode(root->right,data);
    
    else
    return 1;
}

void inOrder(node*root)
{
    if(root != NULL)
    {   
      inOrder(root->left);
      printf("%d ",root->data);
      inOrder(root->right);
    }  
}

void preOrder(node*root)
{
    if(root != NULL)
    {  
      printf("%d ",root->data);
      preOrder(root->left);
      preOrder(root->right); 
    }    
}    

void postOrder(node*root)
{
    if(root != NULL)
    {   
      postOrder(root->left);
      postOrder(root->right);
      printf("%d ",root->data);  
    }    
}

void whoIsTheParent(node*root,node*parent,int data)
{
        if(data < root->data)
        {
            parent = root;
            whoIsTheParent(root->left,parent,data);
        }
        
        else if(data > root->data)
        {
            parent = root;
            whoIsTheParent(root->right,parent,data);
        }
        
        else if(root == NULL)
        {
            printf("\n%d does not exist in this tree...\n",data);
        }
        
        else
        {
            if(parent != NULL)
            {
                printf("\n%d exists\nParent node's data: %d\n",data,parent->data);
            }
            
            else
            {
                printf("\n%d exists and it is the root node...\n",data);
            }
        }
}

void nodeCount(node*root, int*count)
{
    if(root != NULL) 
    {
        *count = *count + 1;
        nodeCount(root->left,count);
        nodeCount(root->right,count);
    }
}

int heightOfTree(node*root)          
{
    if(root == NULL)
    return 0;
    
    // here, we have considered the number of nodes including the root node->farthest leaf node
    // to consider the number of edges definition, return -1 in the NULL case 
    
    int lst = heightOfTree(root->left);
    int rst = heightOfTree(root->right);
    
    return (lst > rst ? lst+ 1 : rst + 1);
}

node* delete(node*root, int data)
{
    if(root == NULL)
    return NULL;
    
    else if(data < root->data)
    {
        root->left = delete(root->left, data);
    }
    
    else if(data > root->data)
    {
        root->right = delete(root->right, data);
    }
    
    else
    {
        if(root->left == NULL)
        {
            node*temp = root->right;
            free(root);
            return temp;
        }
        
        else if(root->right == NULL)
        {
            node*temp = root->left;
            free(root);
            return temp;
        }
        
        node*temp = inPost(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    
    return root;
}

node*inPost(node*root)
{
    node*temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
