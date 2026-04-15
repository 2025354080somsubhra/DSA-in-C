#include<stdio.h>
#include<stdlib.h>

// int main() {
//     int *ptr;
//     // use of malloc
//     int n = printf("Size of Array to be created is : ");
//     scanf("%d",&n);
//     ptr = (int *) malloc(n * sizeof(int));
//     for(int i=0; i<n; i++) {
//         printf("Enter the value no. %d of the array  : ",i);
//         scanf("%d",&ptr[i]);
//     }
//     for(int i=0; i<n; i++) {
//         printf("The value of %d in the array is : %d \n ",i,ptr[i]);
//     }
//     return 0;
// }

// int main() {
//     int *ptr;
//     // use calloc
//     int n = printf("Size of Array to be created is : ");
//     scanf("%d",&n);
//     ptr = (int *) calloc(n, sizeof(int));
//     for(int i = 0; i<n; i++) {
//         printf("The value of %d in the array is : %d\n",i,ptr[i]);
//     }
//     return 0;
// }

int main() {
    int *ptr;
    // use of realloc
    int n = printf("Size of Array to be created is : ");
    scanf("%d",&n);
    ptr = (int *) realloc(ptr, n*sizeof(int));
    for(int i=0; i<n; i++) {
        printf("The value of %d in the array : ",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0; i<n; i++) {
        printf("The value at %d in the array is : %d\n",i,ptr[i]);
    }
    free(ptr); // free the heap
    return 0;
}