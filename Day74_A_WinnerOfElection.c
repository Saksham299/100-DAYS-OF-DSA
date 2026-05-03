#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            count[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(names[i], names[j]) == 0) {
                    count[i]++;
                    count[j] = -1;
                }
            }
        }
    }

    int max = 0;
    char winner[100];

    for (int i = 0; i < n; i++) {
        if (count[i] > max) {
            max = count[i];
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);
    return 0;
}
