#include <stdio.h>  
#include <stdlib.h>  
  
struct node {  
  int data;  
  struct node *right_child;  
  struct node *left_child;  
};  
  
struct node* new_node(int x){  
  struct node *temp;  
  temp = malloc(sizeof(struct node));  
  temp->data = x;  
  temp->left_child = NULL;  
  temp->right_child = NULL;  
  
  return temp;  
}  
  
struct node* insert(struct node * root, int x){  
  if (root == NULL)  
    return new_node(x);  
  else if (x > root->data)  
    root->right_child = insert(root->right_child, x);  
  else   
    root -> left_child = insert(root->left_child, x);  
  return root;  
}  

  
void inorder(struct node *root){  
  if (root != NULL)   
  {  
    inorder(root->left_child);   
    printf(" %d ", root->data);   
    inorder(root->right_child);   
  }  
}  
  
int main() {  
  struct node *root;  
  root = new_node(20);  
  insert(root, 5);  
  insert(root, 1);  
  insert(root, 15);  
  insert(root, 9);  
  insert(root, 7);  
  insert(root, 12);  
  insert(root, 30);  
  insert(root, 25);  
  insert(root, 40);  
  insert(root, 45);  
  insert(root, 42);  
  
  inorder(root);  
  printf("\n");
}  