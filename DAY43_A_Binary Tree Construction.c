#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree level order
struct Node* buildTree() {
    int val;
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct Node* root = newNode(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// Inorder display
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = buildTree();
    inorder(root);
}
