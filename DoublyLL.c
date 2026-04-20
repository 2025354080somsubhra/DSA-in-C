#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// CREATE
void create(int n) {
    struct node *newnode;
    int i = 0;

    while(i < n) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            struct node *temp = head;

            // 🔁 go to last node
            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }

        i++;
    }
}

// DISPLAY
void display() {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// INSERT AT POSITION
void insert_pos(int pos, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if(pos == 1) {
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;

        head = newnode;
    } else {
        struct node *temp = head;
        int i = 1;

        // 🔁 go to (pos-1)
        while(i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }
}

// DELETE FROM POSITION
void delete_pos(int pos) {
    struct node *temp = head;

    if(pos == 1) {
        head = temp->next;

        if(head != NULL)
            head->prev = NULL;

        free(temp);
    } else {
        struct node *prev = NULL;
        int i = 1;

        // 🔁 reach position
        while(i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if(temp->next != NULL)
            temp->next->prev = prev;

        prev->next = temp->next;

        free(temp);
    }
}

// MAIN
int main() {
    int n, choice, pos, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    create(n);

    while(1) {
        printf("\n1.Display 2.Insert 3.Delete 4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: display(); break;

            case 2:
                printf("Enter position & value: ");
                scanf("%d %d", &pos, &val);
                insert_pos(pos, val);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 4: exit(0);
        }
    }
}
