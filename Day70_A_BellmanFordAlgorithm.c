#include <stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Edge edges[100];

    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int dist[100];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

    return 0;
}
