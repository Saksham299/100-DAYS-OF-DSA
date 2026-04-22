#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// PUSH
void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

// POP
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

// DISPLAY
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
