#include<stdio.h>
#define MAX 100

void delete(int LA[], int *N, int K) {

    int j;

    if(K >= *N || K < 0) {
        printf("Underflow\n");
        return;
    }

    for(j = K; j < *N - 1; j++) {
        LA[j] = LA[j + 1];
    }

    *N = *N - 1;
}

int main() {

    int Arr[MAX] = {1,2,3,4,5,6,7,8};
    int K = 3;
    int N = 8;

    delete(Arr, &N, K);

    printf("Updated array is:\n");

    for(int i = 0; i < N; i++) {
        printf("%d ", Arr[i]);
    }

    return 0;
}