#include<stdio.h>
#define MAX 100

void linearSearch(int LA[], int *N, int ITEM) {
    int K = 1, LOC = 0;
    
    while (K <= *N) {
        if(LA[K] == ITEM) {
            LOC = K;
            break;
        }
        K = K+1;
    }
    if(LOC == 0) {
        printf("Item not found");
    } else {
        printf("The location of the item is %d\n",LOC);
    }
}

int main() {
    int Arr[MAX] = {1,2,3,4,5,6,7,8};
    int N = 8;
    int ITEM;
    printf("Enter the element to be searched : ");
    scanf("%d",&ITEM);
    linearSearch(Arr, &N, ITEM);
    return 0;
}