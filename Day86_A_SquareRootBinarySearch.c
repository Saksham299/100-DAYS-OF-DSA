#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int l = 0, r = x, ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}
