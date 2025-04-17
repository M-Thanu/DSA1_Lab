#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Count total nodes
int countNodes() {
    if (head == NULL) return 0;

    int count = 1;
    struct Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Add at beginning
void addAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Add at end
void addAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Add at specific position
void addAtPosition(int value, int pos) {
    int total = countNodes();
    if (pos <= 0 || pos > total + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        addAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    struct Node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    free(temp->next);
    temp->next = head;
}

// Delete at specific position
void deleteAtPosition(int pos) {
    int total = countNodes();
    if (pos <= 0 || pos > total) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Reverse list
void reverseList() {
    if (head == NULL || head->next == head)
        return;

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* last = head;

    do {
        last = last->next;
    } while (last->next != head);

    struct Node* first = head;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;
    last->next = head;
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Search element
void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found.\n", key);
}

// Main function
int main() {
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add at beginning\n2. Add at end\n3. Add at position\n");
        printf("4. Delete first\n5. Delete last\n6. Delete at position\n");
        printf("7. Reverse\n8. Exit\n9. Display\n10. Search\n");
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
                scanf("%d %d", &value, &pos);
                addAtPosition(value, pos);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                reverseList();
                break;
            case 8:
                exit(0);
            case 9:
                display();
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
