#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void displayFrontRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front value: %d\n", queue[front]);
        printf("Rear value: %d\n", queue[rear]);
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Front and Rear\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                displayFrontRear();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
