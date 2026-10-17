#include <stdio.h>

#define INF 99999

int main() {
    int a[20][20], dist[20], visited[20];
    int n, source, i, j, count;
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("Enter 0 for no edge (except diagonal).\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            if (i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        dist[i] = a[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                a[u][j] != INF &&
                dist[u] != INF &&
                dist[u] + a[u][j] < dist[j]) {

                dist[j] = dist[u] + a[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To vertex %d: No path\n", i);
        else
            printf("To vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}