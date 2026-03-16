//Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
void dequeue() {

    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted element: %d\n", front->data);

    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

// Display queue
void display() {

    struct Node* temp = front;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue elements: ");
    display();

    dequeue();

    printf("Queue after deletion: ");
    display();

    return 0;
}