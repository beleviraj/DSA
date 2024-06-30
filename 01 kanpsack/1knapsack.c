#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int p[n], wt[n];
    printf("Enter the profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter the weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    int m;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &m);
    int k[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (wt[i-1] <= w) {
                k[i][w] = max(p[i-1] + k[i-1][w - wt[i-1]], k[i-1][w]);
            } else {
                k[i][w] = k[i-1][w];
            }
        }
    }
    printf("Maximum profit: %d\n", k[n][m]);
    return 0;
}
