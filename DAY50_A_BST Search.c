#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
