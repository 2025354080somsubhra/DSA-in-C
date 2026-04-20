#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node n;

n *head = NULL;

// Create circular linked list
void createLL() {
    n *new, *temp = NULL;
    int p = 0;
    do {
        new = (n *) malloc(sizeof(n));
        if (!new) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter the element: ");
        scanf("%d", &new->data);
        new->link = NULL;

        if (head == NULL) {
            head = temp = new;
            new->link = head;  // circular
        } else {
            temp->link = new;
            temp = new;
            temp->link = head;
        }

        printf("Enter 0 to Continue, 1 to Exit: ");
        scanf("%d", &p);
    } while (p == 0);
}

// Display circular linked list
void display() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    n *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert at position
void insertAtPos(int data, int pos) {
    n *new = (n *) malloc(sizeof(n));
    if (!new) {
        printf("Memory allocation failed!\n");
        return;
    }
    new->data = data;
    new->link = NULL;

    if (pos == 1) {
        if (head == NULL) {
            head = new;
            new->link = head;
        } else {
            n *temp = head;
            while (temp->link != head) temp = temp->link;
            temp->link = new;
            new->link = head;
            head = new;
        }
        return;
    }

    n *temp = head;
    for (int i = 1; i < pos - 1 && temp->link != head; i++) {
        temp = temp->link;
    }
    new->link = temp->link;
    temp->link = new;
}

// Delete at position
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    n *temp = head, *prev = NULL;

    // Case 1: Delete head
    if (pos == 1) {
        if (head->link == head) { // only one node
            free(head);
            head = NULL;
        } else {
            n *last = head;
            while (last->link != head) last = last->link;
            last->link = head->link;
            temp = head;
            head = head->link;
            free(temp);
        }
        return;
    }

    // Case 2: Delete middle/last
    for (int i = 1; i < pos && temp->link != head; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (prev != NULL) {
        prev->link = temp->link;
        free(temp);
    }
}

// Main with switch-case menu
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createLL();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
