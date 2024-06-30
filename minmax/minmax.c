#include<stdio.h>

int minmax(int arr[], int i, int j, int *min, int *max) {
    int mid, min1, max1, min2, max2;
    int cmp = 0;

    if (i == j) {
        *min = arr[i];
        *max = arr[i];
    } else if (i == j - 1) {
        if (arr[i] < arr[j]) {
            *min = arr[i];
            *max = arr[j];
        } else {
            *min = arr[j];
            *max = arr[i];
        }
        cmp++;
    } else {
        mid = (i + j) / 2;
        cmp += minmax(arr, i, mid, &min1, &max1);
        cmp += minmax(arr, mid + 1, j, &min2, &max2);

        if (min1 < min2)
            *min = min1;
        else
            *min = min2;
        if (max1 > max2)
            *max = max1;
        else
            *max = max2;

        cmp += 2;
    }

    return cmp;
}

int main() {
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int i = 0, j = n - 1, min, max;
    int cmp = minmax(arr, i, j, &min, &max);

    printf("\nThe min value is : %d", min);
    printf("\nThe max value is : %d", max);
    printf("\nTotal number of comparisons made: %d\n", cmp);

    return 0;
}
