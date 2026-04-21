struct Node {
    int coeff, power;
    struct Node* next;
};

struct Node* create(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node *res = NULL, *temp = NULL;

    while (p1 && p2) {
        struct Node* newNode;

        if (p1->power > p2->power) {
            newNode = create(p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p2->power > p1->power) {
            newNode = create(p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            newNode = create(p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (!res) res = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return res;
}
