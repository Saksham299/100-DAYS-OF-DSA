#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int flag = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j && matrix[i][j] != 1)
                flag = 0;

            if (i != j && matrix[i][j] != 0)
                flag = 0;
        }
    }

    if (flag)
        printf("Identity Matrix\n");
    else
        printf("Not Identity Matrix\n");

    return 0;
}
