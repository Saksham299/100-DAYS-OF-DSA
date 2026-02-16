#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i, j, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    // Merge arrays
    for(i = 0; i < n1; i++)
        merged[k++] = arr1[i];
    for(i = 0; i < n2; i++)
        merged[k++] = arr2[i];

    // Optional: sort merged array
    for(i = 0; i < k - 1; i++) {
        for(j = i + 1; j < k; j++) {
            if(merged[i] > merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }

    printf("Merged and sorted array:\n");
    for(i = 0; i < k; i++)
        printf("%d ", merged[i]);

    return 0;
}
