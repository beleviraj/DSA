#include<stdio.h>
int binarycmp(int a[], int n) {
    int low = 0, high = n - 1, target, cmp = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &target);

    while (low <= high) {
        int mid = (low + high) / 2;
        cmp++;
        if (target == a[mid]) {
            printf("\nCOMPARISONS REQUIRED ARE : %d", cmp);
            return mid;
        } else if (target < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("\nCOMPARISONS REQUIRED ARE : %d", cmp);
    return -1;
}
int main() {
    int n;
    printf("\nEnter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the array elements in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int x = binarycmp(a, n);
    if (x != -1) {
        printf("\nThe element is at location: %d", x);
    } else {
        printf("\nThe element is not found in the array.");
    }
    return 0;
}
