#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global pointer to the head of the circular linked list

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the circular linked list
void insertAtHead(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
}

// Function to insert a node at the tail of the circular linked list
void insertAtTail(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(int data, int position) {
    struct Node* newNode = createNode(data);
    if (head == NULL || position <= 1) {
        insertAtHead(data);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                printf("Invalid position!\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node at the head of the circular linked list
void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        if (temp->next == head) {
            head = NULL;
        } else {
            struct Node* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            head = head->next;
            lastNode->next = head;
        }
        free(temp);
    }
}

// Function to delete a node at the tail of the circular linked list
void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = head;
        }
        free(temp);
    }
}

// Function to delete a node from a specific position in the circular linked list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (position <= 1) {
        deleteAtHead();
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                printf("Invalid position!\n");
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
}

// Function to search for an element in the circular linked list
int searchElement(int data) {
    int position = 1;
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty. Element not found.\n");
        return -1;
    }
    do {
        if (temp->data == data) {
            printf("Element %d found at position %d.\n", data, position);
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("Element %d not found in the list.\n", data);
    return -1;
}

// Function to display the circular linked list
void displayList() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;
    
    while (1) {
        printf("Circular Linked List Operations:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

