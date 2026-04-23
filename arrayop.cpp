#include<stdio.h>
#define MAX 100

void insert(int LA[], int *N, int K, int ele) {
    if(*N >= MAX) {
        printf("Overflow\n");
        return;
    }
    if(K > *N || K < 0) {
        printf("Invalid Position\n");
        return;
    }
    int j = *N - 1;
    while(j >= K) {
        LA[j+1] = LA[j];
        j--;
    }
    LA[K] = ele;
    *N = *N + 1;
}

void delete(int LA[], int *N, int K) {
    if(K >= *N || K < 0) {
        printf("Underflow\n");
        return;
    }
    for(int j = K; j < *N - 1; j++) {
        LA[j] = LA[j+1];
    }
    *N = *N - 1;
}

void display(int LA[], int N) {
    if(N == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", LA[i]);
    }
    printf("\n");
}

void linearSearch(int LA[], int N, int ele) {
    int LOC = -1;
    for(int i = 0; i < N; i++) {
        if(LA[i] == ele) {
            LOC = i;
            break;   // stop at first match
        }
    }
    if(LOC == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", LOC);
    }
}

void binarySearch(int LA[], int N, int ele) {
    int start = 0, end = N - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(LA[mid] == ele) {
            printf("Element found at position %d\n", mid + 1);
            return;
        }
        else if(LA[mid] < ele) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main() {
    int LA[MAX], N = 0;
    int ch, pos, ele;

    while(1) {
        printf("\nArray Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                printf("Enter element: ");
                scanf("%d", &ele);
                insert(LA, &N, pos, ele);
                break;
            case 2:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                delete(LA, &N, pos);
                break;
            case 3:
                display(LA, N);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                linearSearch(LA, N, ele);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                binarySearch(LA, N, ele);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
