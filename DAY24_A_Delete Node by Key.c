struct Node* deleteKey(struct Node* head, int key) {
    if (head == NULL) return NULL;

    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;

    while (curr->next && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}
