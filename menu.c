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

void delete(int LA[], int *N, int K)
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
    for(int i = 0; i < N; i++) {
        printf("%d ", LA[i]);
    }
    printf("\n");
}

int main()
{
    int Arr[MAX] = {1,2,3,4,5};
    int N = 5;
    int choice, ITEM, K;

    printf("Data Structure \n");
    printf("1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Display Array\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter position: ");
            scanf("%d",&K);

            printf("Enter item: ");
            scanf("%d",&ITEM);

            insert(Arr, &N, K, ITEM);
            display(Arr, N);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d",&K);

            delete(Arr, &N, K);
            display(Arr, N);
            break;

        case 3:
            display(Arr, N);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}