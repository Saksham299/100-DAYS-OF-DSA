#include <stdio.h>
#define SIZE 5

int cq[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    cq[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    printf("Deleted: %d\n", cq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    return 0;
}
