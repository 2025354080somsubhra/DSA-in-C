// factorial using recursive function
// #include<stdio.h>
// long long fact(int n) {
//     if(n == 0 || n == 1) {
//         return 1;
//     } else {
//         return (n * fact(n-1));
//     }
// }

// void input_num(int *n) {
//     printf("Enter a number : ");
//     scanf("%d",n);
// }

// int main() {
//     int k;
//     input_num(&k);
//     printf("The Factorial is : %lld",fact(k));
//     return 0;
// }

// Fibonacci Series using recursive function

#include<stdio.h>

int fib_recur(int n) {
    if (n == 1 || n == 2) {
        return(n-1);
    } else {
        return(fib_recur(n-1) + fib_recur(n-2));
    }
}

void input_num(int *n) {
    printf("Enter a number : ");
    scanf("%d",n);
}

int main() {
    int a;
    input_num(&a);
    printf("The Fibonacci Series is : %d",fib_recur(a));
    return 0;
}