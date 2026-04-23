//Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 7};
    int n = 7;
    int x = 4;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound index = %d\n", lb);
    printf("Upper Bound index = %d\n", ub);

    return 0;
}