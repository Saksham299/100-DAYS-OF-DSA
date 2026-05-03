#include <stdio.h>

int adj[100][100], visited[100], recStack[100];
int n;

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int edges;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (dfs(0))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}
