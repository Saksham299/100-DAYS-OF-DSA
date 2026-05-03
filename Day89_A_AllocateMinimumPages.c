#include <stdio.h>

int isValid(int arr[], int n, int students, int maxPages) {
    int count = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (sum + arr[i] > maxPages) {
            count++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    return count <= students;
}

int main() {
    int n, students;
    scanf("%d %d", &n, &students);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int l = 0, r = 0, ans = -1;

    for (int i = 0; i < n; i++)
        r += arr[i];

    while (l <= r) {
        int mid = (l + r) / 2;

        if (isValid(arr, n, students, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}
