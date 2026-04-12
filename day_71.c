//Implement a hash table using quadratic probing with formula:
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11   // prime size helps reduce clustering
#define EMPTY -1

typedef struct {
    int key;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

// Initialize table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = EMPTY;
    }
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i*i) % TABLE_SIZE;  // quadratic probing
        if (hashTable[newIndex].key == EMPTY) {
            hashTable[newIndex].key = key;
            return;
        }
        i++;
    }
    printf("Table full, cannot insert %d\n", key);
}

// Search using quadratic probing
int search(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i*i) % TABLE_SIZE;
        if (hashTable[newIndex].key == key) {
            return newIndex;
        }
        if (hashTable[newIndex].key == EMPTY) {
            return -1; // not found
        }
        i++;
    }
    return -1;
}

// Display table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != EMPTY)
            printf("[%d] => %d\n", i, hashTable[i].key);
        else
            printf("[%d] => EMPTY\n", i);
    }
}

// Example driver
int main() {
    initTable();

    insert(22);
    insert(1);
    insert(13);
    insert(11);
    insert(24);
    insert(33);

    display();

    int key = 24;
    int pos = search(key);
    if (pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key %d not found\n", key);

    return 0;
}