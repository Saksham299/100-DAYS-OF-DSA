#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];               // primary diagonal
        sum += matrix[i][n - i - 1];       // secondary diagonal
    }

    if (n % 2 == 1)
        sum -= matrix[n/2][n/2];  // remove duplicate center

    printf("%d\n", sum);

    return 0;
}
