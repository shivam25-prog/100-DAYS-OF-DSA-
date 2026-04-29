//Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int* stalls, int n, int k, int dist) {
    int count = 1; // place first cow
    int last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int aggressiveCows(int* stalls, int n, int k) {
    qsort(stalls, n, sizeof(int), cmp);
    int low = 1, high = stalls[n-1] - stalls[0], ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;   // try bigger distance
        } else {
            high = mid - 1;  // reduce distance
        }
    }
    return ans;
}