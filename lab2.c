#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct node {
    int data;
    struct node* next;
};

// Function to create a linked list with 'n' nodes
struct node* createLinkedList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    
    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        newNode = (struct node*) malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }

        // Take user input for node data
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        // If it's the first node, set it as head
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode; // Link previous node to new node
            temp = newNode;       // Move temp to the new node
        }
    }
    return head;
}

// Function to display the linked list
void displayLinkedList(struct node* head) {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free allocated memory
void freeLinkedList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int n;
    
    // User input for number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    // Create the linked list
    struct node* head = createLinkedList(n);

    // Display the linked list
    displayLinkedList(head);

    // Free allocated memory
    freeLinkedList(head);

    return 0;
}
