#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node n;
n *Head = NULL;

void append() {
    n *temp = (n *) malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(Head == NULL) {
        Head = temp;
    } else {
        n *p = Head;
        while(p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}

void display() {
    n *p = Head;

    if(p == NULL) {
        printf("List is empty\n");
        return;
    }

    while(p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int lenNodes() {
    int count = 0;
    n *p = Head;

    while(p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}

void addBegin() {
    n *temp = (n *)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d",&temp->data);

    temp->link = Head;
    Head = temp;
}

void insert() {
    int i=1, loc;
    n *temp = (n *)malloc(sizeof(n));

    printf("Enter value: ");
    scanf("%d",&temp->data);

    printf("Enter position: ");
    scanf("%d",&loc);

    if(loc < 1 || loc > lenNodes()+1) {
        printf("Out of range\n");
        return;
    }

    if(loc == 1) {
        temp->link = Head;
        Head = temp;
    } else {
        n *p = Head;
        while(i < loc-1) {
            p = p->link;
            i++;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

void deleteNode() {
    int i=1, loc;

    if(Head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d",&loc);

    if(loc < 1 || loc > lenNodes()) {
        printf("Invalid position\n");
        return;
    }

    if(loc == 1) {
        n *temp = Head;
        Head = Head->link;
        free(temp);
    } else {
        n *p = Head;
        while(i < loc-1) {
            p = p->link;
            i++;
        }
        n *q = p->link;
        p->link = q->link;
        free(q);
    }
}

void mid_len() {
    int len = lenNodes();

    if(len == 0) {
        printf("List is empty\n");
        return;
    }

    if(len % 2 == 0)
        printf("Middle positions: %d and %d\n", len/2, (len/2)+1);
    else
        printf("Middle position: %d\n", (len+1)/2);
}

int main() {
    int choice;

    printf("Linked List Functions using Switch Case\n");

    while(1) {
        printf("\n Linked List Operations \n");
        printf("1. Append Node\n");
        printf("2. Display List\n");
        printf("3. Count Nodes\n");
        printf("4. Add at Beginning\n");
        printf("5. Insert at Position\n");
        printf("6. Delete Node\n");
        printf("7. Find Middle Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: append(); break;
            case 2: display(); break;
            case 3: printf("Total Nodes = %d\n", lenNodes()); break;
            case 4: addBegin(); break;
            case 5: insert(); break;
            case 6: deleteNode(); break;
            case 7: mid_len(); break;
            case 8: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}