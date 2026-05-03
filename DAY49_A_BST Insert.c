#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int val) {
    if (!root) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = val;
        node->left = node->right = NULL;
        return node;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
