#include<stdio.h>
#define MAX 100

void insert(int LA[], int *N, int K, int ITEM)
{
    int j;

    if(*N >= MAX) {
        printf("Overflow\n");
        return;
    }

    if(K > *N || K < 0) {
        printf("Invalid Position\n");
        return;
    }

    j = *N - 1;

    while(j >= K) {
        LA[j+1] = LA[j];
        j--;
    }

    LA[K] = ITEM;
    *N = *N + 1;

    printf("Element inserted successfully\n");
}

void deleteElement(int LA[], int *N, int K)
{
    int j;

    if(K >= *N || K < 0) {
        printf("Underflow / Invalid Position\n");
        return;
    }

    for(j = K; j < *N - 1; j++) {
        LA[j] = LA[j + 1];
    }

    *N = *N - 1;

    printf("Element deleted successfully\n");
}

void display(int LA[], int N)
{
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

void linearSearch(int LA[], int N, int ITEM)
{
    int LOC = -1;

    for(int i = 0; i < N; i++) {
        if(LA[i] == ITEM) {
            LOC = i;
            break;
        }
    }

    if(LOC == -1) {
        printf("Item not found\n");
    } else {
        printf("Item found at position %d\n", LOC);
    }
}

void menu()
{
    printf("Array Operations \n");
    printf("1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Linear Search\n");
    printf("4. Display Array\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void runner(int Arr[], int *N)
{
    int choice, ITEM, K;

    do {
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter position (0-based index): ");
                scanf("%d", &K);

                printf("Enter item: ");
                scanf("%d", &ITEM);

                insert(Arr, N, K, ITEM);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &K);

                deleteElement(Arr, N, K);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &ITEM);

                linearSearch(Arr, *N, ITEM);
                break;

            case 4:
                display(Arr, *N);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);
}

int main()
{
    int Arr[MAX] = {1, 2, 3, 4, 5};
    int N = 5;
    runner(Arr, &N);
    return 0;
}