#include<stdio.h>

void toh(int n, char src, char aux, char dest) {
    if(n > 0) {
        toh(n-1, src, dest, aux);
        printf("%c --> %c\n", src, dest);
        toh(n-1, aux, src, dest);
    }
}

int main() {
    int n;
    printf("Enter the total number of discs: ");
    scanf("%d", &n);   

    toh(n, 'A', 'B', 'C');
    return 0;
}