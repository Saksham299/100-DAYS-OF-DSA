#include <stdio.h>

int main() {
    int arr[100], n, val, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to remove: ");
    scanf("%d", &val);

    // Two-pointer approach
    for(i = 0; i < n; i++) {
        if(arr[i] != val) {
            arr[j] = arr[i];
            j++;
        }
    }

    printf("Array after removing %d:\n", val);
    for(i = 0; i < j; i++)
        printf("%d ", arr[i]);

    return 0;
}
