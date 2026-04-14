#include<stdio.h>
#define MAX 100

int avail;

void create(int link[], int *start) {
    for(int i = 0; i < MAX-1; i++) {
        link[i] = i + 1;
    }
    link[MAX-1] = -1;
    avail = 0;
    *start = -1;
}

void insertBegin(int data[], int link[], int *start, int val) {
    if(avail == -1) {
        printf("Overflow \n");
        return;
    }

    int p = avail;
    avail = link[p];

    data[p] = val;
    link[p] = *start;
    *start = p;
}

void insertEnd(int data[], int link[], int *start, int val) {
    if(avail == -1) {
        printf("Overflow \n");
        return;
    }

    int p = avail;
    avail = link[p];

    data[p] = val;
    link[p] = -1;

    if(*start == -1) {
        *start = p;
    } else {
        int temp = *start;
        while(link[temp] != -1) {
            temp = link[temp];
        }
        link[temp] = p;
    }
}

void insertPos(int data[], int link[], int *start, int pos, int val) {
    if(avail == -1) {
        printf("Overflow \n");
        return;
    }

    int p = avail;
    avail = link[p];

    data[p] = val;

    if(pos == 1) {
        link[p] = *start;
        *start = p;
        return;
    }

    int temp = *start;
    for(int i = 1; i < pos - 1; i++) {
        if(temp == -1) {
            printf("Out of range \n");
            return;
        }
        temp = link[temp];
    }

    link[p] = link[temp];
    link[temp] = p;
}

void deleteBegin(int link[], int *start) {
    if(*start == -1) {
        printf("Underflow \n");
        return;
    }

    int temp = *start;
    *start = link[temp];

    link[temp] = avail;
    avail = temp;
}

void deleteEnd(int link[], int *start) {
    if(*start == -1) {
        printf("Underflow \n");
        return;
    }

    int temp = *start;

    if(link[temp] == -1) {
        *start = -1;
        link[temp] = avail;
        avail = temp;
        return;
    }

    while(link[link[temp]] != -1) {
        temp = link[temp];
    }

    int last = link[temp];
    link[temp] = -1;

    link[last] = avail;
    avail = last;
}

void deletePos(int link[], int *start, int pos) {
    if(*start == -1) {
        printf("Underflow\n");
        return;
    }

    if(pos == 1) {
        deleteBegin(link, start);
        return;
    }

    int temp = *start;
    for(int i = 1; i < pos - 1; i++) {
        if(link[temp] == -1) {
            printf("Out of range \n");
            return;
        }
        temp = link[temp];
    }

    int del = link[temp];
    if(del == -1) {
        printf("Out of range \n");
        return;
    }

    link[temp] = link[del];

    link[del] = avail;
    avail = del;
}

void display(int data[], int link[], int start) {
    if(start == -1) {
        printf("List empty \n");
        return;
    }

    int temp = start;
    while(temp != -1) {
        printf("%d -> ", data[temp]);
        temp = link[temp];
    }
    printf("NULL\n");
}

void countNodes(int link[], int start) {
    int count = 0;
    int temp = start;

    while(temp != -1) {
        count++;
        temp = link[temp];
    }

    printf("Total nodes: %d\n", count);
}

void menu(int d[], int l[], int *st) {
    int ch, ele, pos;

    while(1) {
        printf(" Array Linked List Menu Driven Program \n");
        printf("1. Insert Begin\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Begin\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &ele);
                insertBegin(d, l, st, ele);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &ele);
                insertEnd(d, l, st, ele);
                break;

            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &ele);
                insertPos(d, l, st, pos, ele);
                break;

            case 4:
                deleteBegin(l, st);
                break;

            case 5:
                deleteEnd(l, st);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(l, st, pos);
                break;

            case 7:
                display(d, l, *st);
                break;

            case 8:
                countNodes(l, *st);
                break;

            case 9:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int d[MAX], l[MAX];
    int st, ch, ele, pos;

    create(l, &st);
    menu(d,l,&st);
    return 0;
}