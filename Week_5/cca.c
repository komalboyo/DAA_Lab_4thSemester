#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the Closest Common Ancestor (CCA)
struct TreeNode* findCCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return findCCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return findCCA(root->right, n1, n2);
    return root;
}

int main() {
    // Constructing the BST
    struct TreeNode* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct TreeNode* cca = findCCA(root, n1, n2);
    printf("Closest Common Ancestor of %d and %d is: %d\n", n1, n2, cca->data);

    return 0;
}
