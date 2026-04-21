#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to find intersection point
int getIntersectionNode(struct Node* headA, struct Node* headB) {
    struct Node *a = headA, *b = headB;

    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    if (a)
        return a->data;
    return -1;
}
