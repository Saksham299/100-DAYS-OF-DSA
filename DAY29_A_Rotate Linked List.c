struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0) return head;

    struct Node *temp = head;
    int len = 1;

    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head; // make circular

    k = k % len;
    k = len - k;

    while (k--) temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}
