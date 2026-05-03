#include <stdio.h>

struct Meeting {
    int start, end;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j].end < arr[i].end) {
                struct Meeting t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    int count = 1, last = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= last) {
            count++;
            last = arr[i].end;
        }
    }

    printf("%d", count);
    return 0;
}
