//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

#define TABLE_SIZE 10007

Node* hashTable[TABLE_SIZE];

// Simple hash function
int hashFunc(int sum) {
    if (sum < 0) sum = -sum;
    return sum % TABLE_SIZE;
}

// Insert into hash table
void insert(int sum, int index) {
    int h = hashFunc(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash table
int search(int sum) {
    int h = hashFunc(sum);
    Node* cur = hashTable[h];
    while (cur) {
        if (cur->sum == sum) return cur->index;
        cur = cur->next;
    }
    return -1;
}

int maxLenZeroSumSubarray(int arr[], int n) {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = NULL;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }

        int prevIndex = search(prefixSum);
        if (prevIndex != -1) {
            int len = i - prevIndex;
            if (len > maxLen) maxLen = len;
        } else {
            insert(prefixSum, i);
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest zero-sum subarray: %d\n", maxLenZeroSumSubarray(arr, n));
    return 0;
}