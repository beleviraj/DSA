#include <stdio.h>

int partition(int arr[], int lb, int ub, int *cmp) {
    int pivot = arr[lb], start = lb, end = ub;

    while (start < end) {
        while (arr[start] <= pivot && start < ub) {
            start++;
            (*cmp)++;
        }
        while (arr[end] > pivot) {
            end--;
            (*cmp)++;
        }
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void quicksort(int arr[], int lb, int ub, int *cmp) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub, cmp);
        quicksort(arr, lb, loc - 1, cmp);
        quicksort(arr, loc + 1, ub, cmp);
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int lb = 0, ub = n - 1, cmp = 0;
    quicksort(a, lb, ub, &cmp);

    printf("\nThe sorted array is = ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
    printf("\nThe number of comparisons are: %d", cmp);

    return 0;
}
