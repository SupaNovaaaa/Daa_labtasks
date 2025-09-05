#include <stdio.h>
#include <limits.h>

// Function to find maximum crossing subarray sum
int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int left_sum = INT_MIN;

    // Include elements on left of mid
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    // Include elements on right of mid
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

// Function to return maximum subarray sum in arr[l..r]
int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)  // base case: only one element
        return arr[l];

    int m = (l + r) / 2;

    // Return maximum of three cases:
    // 1. max subarray sum in left half
    // 2. max subarray sum in right half
    // 3. max subarray sum crossing the mid
    int left_max = maxSubArraySum(arr, l, m);
    int right_max = maxSubArraySum(arr, m + 1, r);
    int cross_max = maxCrossingSum(arr, l, m, r);

    // return maximum of three
    if (left_max >= right_max && left_max >= cross_max)
        return left_max;
    else if (right_max >= left_max && right_max >= cross_max)
        return right_max;
    else
        return cross_max;
}

int main() {
    int arr[] = {2, -4, 3, -1, 2, -4, 3, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, 0, n - 1);

    printf("Maximum Subarray Sum is %d\n", max_sum);

    return 0;
}
