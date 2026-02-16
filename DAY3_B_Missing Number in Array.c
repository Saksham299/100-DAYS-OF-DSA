#include <stdio.h>

int main() {
    int arr[100], n, i, sum = 0;

    printf("Enter number of elements (n-1): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Total sum of numbers from 1 to n+1
    int total = (n + 1) * (n + 2) / 2;

    int missing = total - sum;
    printf("Missing number is: %d\n", missing);

    return 0;
}
