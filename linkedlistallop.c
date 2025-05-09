#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Add at beginning
void addAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Add at end
void addAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Add at specific position
void addAtPosition(int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Reverse the list
void reverse() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

// Display list
void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 10. Search element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Main function with menu
int main() {
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add at beginning\n2. Add at end\n3. Add at position\n");
        printf("4. Delete first node\n5. Delete last node\n6. Delete at position\n");
        printf("7. Reverse list\n8. Exit\n9. Display list\n10. Search element\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                addAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                addAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                addAtPosition(value, position);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                reverse();
                break;
            case 8:
                exit(0);
            case 9:
                display();
                break;
            case 10:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
