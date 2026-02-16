#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        count++; // Count each comparison
        if(arr[i] == key) {
            found = 1;
            printf("Element %d found at position %d\n", key, i + 1);
            break;
        }
    }

    if(!found) {
        printf("Element %d not found in the array.\n", key);
    }

    printf("Number of comparisons made: %d\n", count);

    return 0;
}
