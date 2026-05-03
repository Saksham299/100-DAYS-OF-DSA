#include <stdio.h>

int adj[100][100], visited[100];
int n;

int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int edges;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    if (dfs(0, -1))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}
