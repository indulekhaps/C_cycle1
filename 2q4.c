#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the tail of the linked list
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    
    if (position == 0) {
        insertAtHead(head, data);
    } else {
        struct Node* current = *head;
        int currentPosition = 0;
        
        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        
        newNode->prev = current;
        newNode->next = current->next;
        current->next = newNode;
        
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
    }
}

// Function to delete a node at the head of the linked list
void deleteAtHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    free(temp);
}

// Function to delete a node at the tail of the linked list
void deleteAtTail(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = *head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
    
    free(current);
}

// Function to delete a node from a given position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid operation.\n");
        return;
    }
    
    if (position == 0) {
        deleteAtHead(head);
    } else {
        struct Node* current = *head;
        int currentPosition = 0;
        
        while (current != NULL && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }
        
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            *head = current->next;
        }
        
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        
        free(current);
    }
}

// Function to search for an element in the linked list
int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1; // Element not found
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at position\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at position\n");
        printf("7. Search element\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(&head, data);
                break;

            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertAtTail(&head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteAtHead(&head);
                break;

            case 5:
                deleteAtTail(&head);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 8:
                printf("Linked List: ");
                display(head);
                break;
}  
}              
    }            


