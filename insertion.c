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
}

int main() {
    int Arr[MAX] = {1,2,3,4,5};
    int ITEM = 10;
    int K = 2;
    int N = 5;
    int i;

    insert(Arr, &N, K, ITEM);

    printf("Updated Array:\n");

    for(i = 0; i < N; i++) {
        printf("%d ", Arr[i]);
    }

    return 0;
}