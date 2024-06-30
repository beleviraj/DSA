#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
void printMatrix(int G[MAX][MAX], int n) {
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", G[i][j]);
            }
        }
        printf("\n");
    }
}
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int G[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] != INF && dist[u] != INF && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
            }
        }
    }
    printf("\nVertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}
int main() {
    int G[MAX][MAX], n, u;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            if (i != j && G[i][j] == 0) {
                G[i][j] = INF; 
            }
        }
    }
    printMatrix(G, n);
    printf("\nEnter the starting node: ");
    scanf("%d", &u);
    dijkstra(G, n, u);
    return 0;
}
