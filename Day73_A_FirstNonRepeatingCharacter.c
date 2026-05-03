#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0};

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        freq[str[i]]++;

    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i]] == 1) {
            printf("%c", str[i]);
            return 0;
        }
    }

    printf("No Non-Repeating Character");
    return 0;
}
