#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[100];

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

int main() {
    int n, edges;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
