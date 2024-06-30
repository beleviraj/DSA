#include <stdio.h>
typedef struct {
    int obj_num;
    int profit;
    int weight;
    float ratio;
} Object;
void bubbleSort(Object arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                Object temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
float knapsack(Object a[], int n) {
    int m;
    float p = 0.0;
    int i = 0;
    printf("\nEnter the capacity: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        if (m > 0 && a[i].weight <= m) {
            m -= a[i].weight;
            p += a[i].profit;
        } else {
            break;
        }
    }
    if (m > 0 && i < n) {
        p += a[i].profit * ((float)m / a[i].weight);
    }
    return p;
}
int main() {
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int p[n], w[n];
    float r[n];
    Object objects[n];
    printf("\nEnter the profits of objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        objects[i].profit = p[i];
        objects[i].obj_num = i + 1;
    }
    printf("\nEnter the weights of objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        objects[i].weight = w[i];
    }
    printf("\nOBJECTS\tPROFIT\tWEIGHTS\tRATIOS\n");
    for (int i = 0; i < n; i++) {
        r[i] = ((float)p[i] / w[i]);
        objects[i].ratio = r[i];
        printf("x%d\t%d\t%d\t%.2f\n", i + 1, p[i], w[i], r[i]);
    }
    bubbleSort(objects, n);
    printf("\nSorted Table:\n");
    printf("OBJECTS\tPROFIT\tWEIGHTS\tRATIOS\n");
    for (int i = 0; i < n; i++) {
        printf("x%d\t%d\t%d\t%.2f\n", objects[i].obj_num,
         objects[i].profit, objects[i].weight, objects[i].ratio);
    }
    float totalProfit = knapsack(objects, n);
    printf("\nThe total profit is: %.2f\n", totalProfit);
    return 0;
}
