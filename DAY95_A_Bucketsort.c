#include <stdio.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[100];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    float bucket[10][100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * 10;
        bucket[idx][count[idx]++] = arr[i];
    }

    for (int i = 0; i < 10; i++)
        insertionSort(bucket[i], count[i]);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%.2f ", bucket[i][j]);

    return 0;
}
