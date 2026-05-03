#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i*i) % SIZE] != -1) {
        i++;
    }

    hashTable[(index + i*i) % SIZE] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", hashTable[i]);
}

int main() {
    init();

    int n, key;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
