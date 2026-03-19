#include<stdio.h>
#define MAX 100

int binarySearch(int LA[], int N, int ITEM) {
    int start = 0 , end = N - 1;

    while(start <= end) {
        int mid = (start + end)/2;
        if(LA[mid] == ITEM) {
            return mid;
        } else if(ITEM < LA[mid]) {
            end = mid-1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int Arr[MAX] = {1,2,3,4,5,6,7,8};
    int N = 8;
    int ITEM;
    printf("Enter the Element to be Searched : ");
    scanf("%d",&ITEM);

    int res = binarySearch(Arr,N,ITEM);

    if(res == -1) {
        printf("Element not found \n");
    } else {
        printf("Element found at the position %d\n",res);
    }
    return 0;
}