#include <stdio.h>

struct Interval {
    int start, end;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[j].start < arr[i].start) {
                struct Interval t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }

    int s = arr[0].start, e = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= e) {
            if (arr[i].end > e)
                e = arr[i].end;
        } else {
            printf("%d %d\n", s, e);
            s = arr[i].start;
            e = arr[i].end;
        }
    }

    printf("%d %d", s, e);
    return 0;
}
