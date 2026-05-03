#include <stdio.h>

int adj[100][100], visited[100], stack[100];
int top = -1, n;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i])
            dfs(i);
    }

    stack[++top] = node;
}

int main() {
    int edges;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    while (top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}
