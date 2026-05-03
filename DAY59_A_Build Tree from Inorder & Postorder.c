#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build Tree Function
struct Node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Last element of postorder is root
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = newNode(curr);

    // If leaf node
    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, curr);

    // IMPORTANT: build right first
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left  = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Preorder print (to verify)
void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Driver Code
int main() {
    int inorder[]   = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder of constructed tree:\n");
    preorder(root);

    return 0;
}
