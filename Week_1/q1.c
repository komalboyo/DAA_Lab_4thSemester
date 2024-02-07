#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node *lchild;
	struct Node *rchild;
}Node;

typedef struct Node* Nodeptr;

Nodeptr createBST(Nodeptr root, int x){
	if (root == NULL){
		root = (Nodeptr)malloc(sizeof(Node));
		root->value = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return root;
	}
	else{
		if (x > root->value){
			root->rchild = createBST(root->rchild, x);
		}
		if (x < root->value){
			root->lchild = createBST(root->lchild, x);
		}
		else if (x == root->value){
			printf("Duplicate value\n");
		}
		return root;
	}
}

void inorder(Nodeptr root){
	if (root==NULL) return;
	inorder (root->lchild);
	printf("%d  ", root->value);
	inorder(root->rchild);
}

void preorder(Nodeptr root){
	if (root==NULL) return;
	printf("%d  ", root->value);
	preorder (root->lchild);
	preorder(root->rchild);
}

void postorder(Nodeptr root){
	if (root==NULL) return;
	postorder (root->lchild);
	postorder(root->rchild);
	printf("%d  ", root->value);
}

int main(){
	printf("Enter the value of root node: ");
	int x;
	scanf("%d", &x);
	Nodeptr root = NULL;  //had to be added 
	root = createBST(root, x);
	printf("Enter node value (-1 to stop): ");
	scanf("%d", &x);
	while (x!=-1){
		root = createBST(root, x);
		printf("Enter node value (-1 to stop): ");
		scanf("%d", &x);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}