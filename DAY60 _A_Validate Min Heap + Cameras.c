int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2*i + 1]) return 0;
        if (2*i + 2 < n && arr[i] > arr[2*i + 2]) return 0;
    }
    return 1;
}
