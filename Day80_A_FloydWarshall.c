#include <stdio.h>
#define INF 9999

int main() {
    int n;
    scanf("%d", &n);

    int dist[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    return 0;
}
