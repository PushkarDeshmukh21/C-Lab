#include <stdio.h> 
#include <stdlib.h> 
struct node { 
 int data; 
 struct node *left; 
 struct node *right; 
}; 
struct node* createNode(int data) { 
 struct node* node = (struct node*)malloc(sizeof(struct node)); 
 node->data = data; 
 node->left = NULL; 
 node->right = NULL; 
 return node; 
} 
struct node* insertNode(struct node* node, int data) { 
 if (node == NULL) return createNode(data); 
 if (data < node->data) 
 node->left = insertNode(node->left, data); 
 else if (data > node->data) 
 node->right = insertNode(node->right, data); 
 return node; 
} 
void inOrderTraversal(struct node* node) { 
 if (node == NULL) return; 
 inOrderTraversal(node->left); 
 printf("%d ", node->data); 
 inOrderTraversal(node->right); 
} 
void preOrderTraversal(struct node* node) { 
 if (node == NULL) return; 
 printf("%d ", node->data); 
 preOrderTraversal(node->left); 
 preOrderTraversal(node->right); 
} 
void postOrderTraversal(struct node* node) { 
 if (node == NULL) return; 
 postOrderTraversal(node->left); 
 postOrderTraversal(node->right); 
 printf("%d ", node->data); 
} 
int main() { 
 struct node* root = NULL; 
 int data, choice; 
 while (1) { 
 printf("\nBinary Search Tree Operations:\n"); 
 printf("1. Insert\n"); 
 printf("2. In-Order Traversal\n"); 
 printf("3. Pre-Order Traversal\n"); 
 printf("4. Post-Order Traversal\n"); 
 printf("5. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 printf("Enter data to insert: "); 
 scanf("%d", &data); 
 root = insertNode(root, data); 
 break; 
 case 2: 
 printf("In-Order Traversal: "); 
 inOrderTraversal(root); 
 break; 
 case 3: 
 printf("Pre-Order Traversal: "); 
 preOrderTraversal(root); 
 break; 
 case 4: 
 printf("Post-Order Traversal: "); 
 postOrderTraversal(root); 
 break; 
 case 5: 
 exit(0); 
 default: 
 printf("Invalid choice\n"); 
 } 
 } 
 return 0; 
} 
