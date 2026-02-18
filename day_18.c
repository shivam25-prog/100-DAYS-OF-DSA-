 //Given  array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    
    k = k % n;

    int temp[n];

    // Place last k elements at the front
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Place remaining elements
    for(int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
