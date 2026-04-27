// Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>

int integerSqrt(int x) {
    if (x == 0 || x == 1) return x;

    int low = 1, high = x, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x = 8;
    printf("Integer square root of %d is %d\n", x, integerSqrt(x));
    return 0;
}