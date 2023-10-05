#include <stdio.h>
#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}
void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}
void displayFront() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void displayRear() {
    if (rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}
int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayRear();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
 return 0;
}
