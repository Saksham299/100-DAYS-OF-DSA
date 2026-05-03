#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0};

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;

        if (freq[str[i]] == 2) {
            printf("%c", str[i]);
            return 0;
        }
    }

    printf("No Repetition");
    return 0;
}
