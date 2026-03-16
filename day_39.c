//Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insertion)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while(index > 0 && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Insert element
void insert(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Heapify Down (for deletion)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Delete minimum element
void deleteMin() {
    if(size == 0) {
        printf("Heap is empty\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display heap
void display() {
    for(int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {

    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);

    printf("Min Heap: ");
    display();

    deleteMin();

    printf("After deleting root: ");
    display();

    return 0;
}