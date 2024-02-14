#include <stdio.h>
#include <stdlib.h>
int n=0;
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        n++;
        inOrderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int nodeValue;

    printf("Input a value to insert into the binary search tree (enter -1 to stop): ");
    scanf("%d", &nodeValue);
    while (nodeValue != -1) {
        root = insertNode(root, nodeValue);
        printf("Input a value to insert into the binary search tree (enter -1 to stop): ");
        scanf("%d", &nodeValue);
    }

    printf("\nIn-order Traversal (Sorted Order) of the Binary Search Tree: \n");
    inOrderTraversal(root);

    printf("%d is the number of nodes\n", n);
}
