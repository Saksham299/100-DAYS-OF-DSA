#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, inv = 0;

    while (i <= mid-1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
    }

    while (i <= mid-1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv = 0;
    if (right > left) {
        mid = (left + right) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid+1, right);
        inv += merge(arr, temp, left, mid+1, right);
    }
    return inv;
}

int main() {
    int n, arr[100], temp[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", mergeSort(arr, temp, 0, n-1));
    return 0;
}
