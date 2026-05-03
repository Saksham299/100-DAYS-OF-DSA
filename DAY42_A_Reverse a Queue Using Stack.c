// Step 1: Include libraries
#include <stdio.h>
#include <stdlib.h>

// Step 2: Define queue structure
#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Step 3: Enqueue function
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

// Step 4: Dequeue function
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Step 5: Reverse using stack
void reverseQueue() {
    int stack[MAX];
    int top = -1;

    // Move queue → stack
    while (front <= rear) {
        stack[++top] = dequeue();
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Move stack → queue
    while (top >= 0) {
        enqueue(stack[top--]);
    }
}

// Step 6: Display
void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

// Step 7: Main
int main() {
    enqueue(1); enqueue(2); enqueue(3); enqueue(4);

    reverseQueue();

    display(); // Output: 4 3 2 1
}
