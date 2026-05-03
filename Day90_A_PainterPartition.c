#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return 0;

        if (time + arr[i] > maxTime) {
            painters++;
            time = arr[i];
        } else {
            time += arr[i];
        }
    }
    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int l = 0, r = 0, ans = -1;

    for (int i = 0; i < n; i++)
        r += arr[i];

    while (l <= r) {
        int mid = (l + r) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}
