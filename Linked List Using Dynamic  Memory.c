#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node n;

n *head = NULL;

void createLL() {
    int ele, tt;
    printf("Enter total elements: ");
    scanf("%d",&tt);

    for(int i=0; i<tt; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d",&ele);

        n *newNode = (n*) malloc(sizeof(n));
        newNode->data = ele;
        newNode->link = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            n *temp = head;
            while(temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }
}

void displayLL() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    n *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void insertFirst(int val) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = val;
    newNode->link = head;
    head = newNode;
}

void insertLast(int val) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = val;
    newNode->link = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        n *temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void insertPos(int val, int pos) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = val;

    if(pos == 1) {
        newNode->link = head;
        head = newNode;
        return;
    }

    n *temp = head;
    for(int i = 1; i < pos - 1; i++) {
        if(temp == NULL) {
            printf("Out of range\n");
            return;
        }
        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

void deleteFirst() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    n *temp = head;
    head = head->link;
    free(temp);
}

void deleteLast() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->link == NULL) {
        free(head);
        head = NULL;
        return;
    }

    n *temp = head;
    while(temp->link->link != NULL) {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

void deletePos(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        n *temp = head;
        head = head->link;
        free(temp);
        return;
    }

    n *temp = head;
    for(int i = 1; i < pos - 1; i++) {
        if(temp->link == NULL) {
            printf("Out of range\n");
            return;
        }
        temp = temp->link;
    }

    n *del = temp->link;
    if(del == NULL) {
        printf("Out of range\n");
        return;
    }

    temp->link = del->link;
    free(del);
}

int count() {
    int c = 0;
    n *temp = head;
    while(temp != NULL) {
        c++;
        temp = temp->link;
    }
    return c;
}

int main() {
    int ch, val, pos;

    while(1) {
        printf("Linked List Menu\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert First\n");
        printf("4. Insert Last\n");
        printf("5. Insert Position\n");
        printf("6. Delete First\n");
        printf("7. Delete Last\n");
        printf("8. Delete Position\n");
        printf("9. Count Node\n");
        printf("10. Exit\n");

        printf("\n Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                createLL();
                break;

            case 2:
                displayLL();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFirst(val);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                insertLast(val);
                break;

            case 5:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertPos(val, pos);
                break;

            case 6:
                deleteFirst();
                break;

            case 7:
                deleteLast();
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 9: {
                int b = count();
                printf("Number of nodes: %d\n", b);
                break;
            }

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
