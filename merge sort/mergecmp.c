#include <stdio.h>
int merge(int arr[], int lb, int mid, int ub, int n) {
    int b[n];
    int i = lb, j = mid + 1, k = lb;
    int cmp=0;

    while (i <= mid && j <= ub) {
        if (arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
        cmp++;
    }
    if(i>mid){
    while (j <= ub) {
        b[k] = arr[j];
        j++;
        k++;
    }
    }
    else{
    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }
    }
    for (int i = lb; i <= ub; i++) {
        arr[i] = b[i];
    }
    return cmp;
}

int mergesort(int arr[], int lb, int ub, int n) {
    int cmp = 0;
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        cmp += mergesort(arr, lb, mid, n);
        cmp += mergesort(arr, mid + 1, ub, n);
        cmp += merge(arr, lb, mid, ub, n);
    }
    return cmp;
}


int main() {
    int n,x;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int lb = 0, ub = n - 1;
    x=mergesort(a, lb, ub, n);
    
    printf("\nThe number of comparisons required are: %d",x);
    printf("\nThe sorted array is = ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }


    return 0;
}
