#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
typedef struct Node n;

n *head = NULL;

void createLL(int tt) {
    for(int i=0; i<tt; i++) {
        int ele;
        printf("Enter value %d: ", i+1);
        scanf("%d",&ele);

        n *newNode = (n*) malloc(sizeof(n));
        newNode->data = ele;

        if(head == NULL) {
            head = newNode;
            head->link = head;   // circular
        } else {
            n *temp = head;
            while(temp->link != head) {
                temp = temp->link;
            }
            temp->link = newNode;
            newNode->link = head;
        }
    }
}

void displayLL() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    n *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while(temp != head);
    printf("(head)\n");
}

void insertPos(int val, int pos) {
    n *newNode = (n*) malloc(sizeof(n));
    newNode->data = val;

    if(pos == 1) {
        // Insert at beginning
        n *last = head;
        while(last->link != head) {
            last = last->link;
        }
        newNode->link = head;
        last->link = newNode;
        head = newNode;
        return;
    }

    n *temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->link;
        if(temp == head) {
            printf("Out of range\n");
            free(newNode);
            return;
        }
    }
    newNode->link = temp->link;
    temp->link = newNode;
}

void deletePos(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        n *last = head;
// 1. Traverse to the end of the circular list
while (last->link != head) {
    last = last->link;
}

n *temp = head;
// 2. If head points to itself, it's the last node; set head to NULL
// Otherwise, move head forward and relink the last node
if (head == last) {
    head = NULL;
} else {
    head = head->link;
    last->link = head;
}

free(temp);

        return;
    }

    n *temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->link;
        if(temp->link == head) {
            printf("Out of range\n");
            return;
        }
    }

    n *del = temp->link;
    if(del == head) {
        printf("Out of range\n");
        return;
    }
    temp->link = del->link;
    free(del);
}

int count() {
    if(head == NULL) return 0;
    int c=0;
    n *temp = head;
    do {
        c++;
        temp = temp->link;
    } while(temp != head);
    return c;
}

int main() {
    int ch, val, pos, tt;

    while(1) {
        printf("\nCircular Linked List Menu\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                printf("Enter total elements: ");
                scanf("%d",&tt);
                createLL(tt);
                break;
            case 2:
                displayLL();
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d",&val,&pos);
                insertPos(val,pos);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d",&pos);
                deletePos(pos);
                break;
            case 5:
                printf("Number of nodes: %d\n", count());
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
