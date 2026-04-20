#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node n;

n *head = NULL;

// Create a new node
n* createNode(int data) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at position
void insertAtPos(int data, int pos) {
    n *newNode = createNode(data);

    if (pos == 1) {  // insert at beginning
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        return;
    }

    n *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at position
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    n *temp = head;

    if (pos == 1) {  // delete head
        head = head->next;
        if (head != NULL) head->prev = NULL;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

// Display list forward
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    n *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main program
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
