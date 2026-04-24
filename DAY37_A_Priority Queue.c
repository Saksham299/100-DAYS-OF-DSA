#include <stdio.h>
#define SIZE 5

int pq[SIZE], n = 0;

void insert(int x) {
    int i;
    for (i = n - 1; i >= 0 && pq[i] > x; i--)
        pq[i + 1] = pq[i];
    pq[i + 1] = x;
    n++;
}

void delete() {
    printf("Deleted: %d\n", pq[0]);
    for (int i = 1; i < n; i++)
        pq[i - 1] = pq[i];
    n--;
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    delete();
    return 0;
}
