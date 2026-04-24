#include <stdio.h>
#define SIZE 5

int dq[SIZE], front = -1, rear = -1;

void insertFront(int x) {
    if (front == 0) return;
    if (front == -1) front = rear = 0;
    else front--;
    dq[front] = x;
}

void insertRear(int x) {
    if (rear == SIZE - 1) return;
    if (rear == -1) front = rear = 0;
    else rear++;
    dq[rear] = x;
}

int main() {
    insertFront(10);
    insertRear(20);
    return 0;
}
