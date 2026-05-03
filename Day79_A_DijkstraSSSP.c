#include <stdio.h>
#define INF 9999

int minDist(int dist[], int visited[], int n) {
    int min = INF, idx;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int dist[100], visited[100] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDist(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
