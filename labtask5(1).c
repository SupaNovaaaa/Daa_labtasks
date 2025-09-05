#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax minmax_divide_conquer(int arr[], int l, int r) {
    MinMax result, leftRes, rightRes;

    // Base case: single element
    if (l == r) {
        result.min = arr[l];
        result.max = arr[l];
        return result;
    }

    // Base case: two elements (only 1 comparison)
    if (r == l + 1) {
        if (arr[l] < arr[r]) {
            result.min = arr[l];
            result.max = arr[r];
        } else {
            result.min = arr[r];
            result.max = arr[l];
        }
        return result;
    }

    // Divide into halves
    int mid = l + (r - l) / 2;
    leftRes  = minmax_divide_conquer(arr, l, mid);
    rightRes = minmax_divide_conquer(arr, mid + 1, r);

    // Conquer: combine results (2 comparisons)
    result.min = (leftRes.min < rightRes.min) ? leftRes.min : rightRes.min;
    result.max = (leftRes.max > rightRes.max) ? leftRes.max : rightRes.max;

    return result;
}

int main(void) {
    int arr[] = {7, -3, 12, 5, 9, 0, 18, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax dc = minmax_divide_conquer(arr, 0, n - 1);

    printf("Divide & Conquer -> min: %d, max: %d\n", dc.min, dc.max);

    return 0;
}
