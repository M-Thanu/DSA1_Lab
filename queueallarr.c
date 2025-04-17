#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    front++;
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to peek.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations (Array) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 5:
            if (isFull())
                printf("Queue is full.\n");
            else
                printf("Queue is not full.\n");
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
