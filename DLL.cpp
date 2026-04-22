#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node n;

n *head = NULL;

// Create doubly linked list
void createLL() {
    int ele, tt;
    printf("Enter total elements: ");
    scanf("%d", &tt);

    for(int i = 0; i < tt; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &ele);

        n *newNode = (n*) malloc(sizeof(n));
        newNode->data = ele;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            n *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Display list
void displayLL() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    n *temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at position
void insertPos(int val, int pos) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(pos == 1) {
        newNode->next = head;
        if(head != NULL) head->prev = newNode;
        head = newNode;
        return;
    }

    n *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at position
void deletePos(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    n *temp = head;

    if(pos == 1) {
        head = head->next;
        if(head != NULL) head->prev = NULL;
        free(temp);
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if(temp->prev != NULL) temp->prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int ch, val, pos;

    while(1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                createLL();
                break;
            case 2:
                displayLL();
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertPos(val, pos);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
