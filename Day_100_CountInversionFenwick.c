#include <stdio.h>

int BIT[1000];

void update(int i, int n) {
    while (i <= n) {
        BIT[i]++;
        i += i & (-i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & (-i);
    }
    return sum;
}

int main() {
    int n, arr[1000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int inv = 0;

    for (int i = n-1; i >= 0; i--) {
        inv += query(arr[i]-1);
        update(arr[i], n);
    }

    printf("%d", inv);
    return 0;
}
