#include <stdio.h>

int main() {
    int n, arr[100], count[100] = {0}, output[100];
    scanf("%d", &n);

    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    for (int i = 0; i < n; i++) count[arr[i]]++;

    for (int i = 1; i <= max; i++) count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) printf("%d ", output[i]);

    return 0;
}
