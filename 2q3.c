#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Initialize the head of the linked list to NULL

// Function to insert a new node at the head of the linked list
void insertAtHead(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the tail of the linked list
void insertAtTail(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

// Function to insert a new node at a specific position in the linked list
void insertAtPosition(int value, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0 || head == NULL) {
        insertAtHead(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = head;
    int i = 1;
    while (i < position && current->next != NULL) {
        current = current->next;
        i++;
    }

    if (i < position) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node from the head of the linked list
void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the tail of the linked list
void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to delete a node from a specific position in the linked list
void deleteAtPosition(int position) {
    if (position < 0 || head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (position == 0) {
        deleteAtHead();
        return;
    }

    struct Node* current = head;
    struct Node* previous = NULL;
    int i = 0;

    while (current != NULL && i < position) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

// Function to search for an element in the linked list
int search(int value) {
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1; // Element not found
}

// Function to display the linked list
void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;
    
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert at head: ");
                scanf("%d", &value);
                insertAtHead(value);
                break;
                
            case 2:
                printf("Enter the value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(value);
                break;
                
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
                
            case 4:
                deleteAtHead();
                break;
                
            case 5:
                deleteAtTail();
                break;
                
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
                
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                position = search(value);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
                
            case 8:
                display();
                break;
                
            case 9:
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

