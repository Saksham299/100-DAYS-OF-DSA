#include <stdio.h>
#define INF 9999

int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int parent[100], key[100], mstSet[100] = {0};

    for (int i = 0; i < n; i++)
        key[i] = INF;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += graph[i][parent[i]];

    printf("%d", cost);
    return 0;
}
