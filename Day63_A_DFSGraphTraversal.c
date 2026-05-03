#include <stdio.h>

int adj[100][100], visited[100];
int n;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    int edges;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(0);
    return 0;
}
