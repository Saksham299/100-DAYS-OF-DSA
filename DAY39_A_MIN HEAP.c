#include <stdio.h>

int heap[100], size = 0;

void insert(int x) {
    int i = size++;
    heap[i] = x;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    return 0;
}
