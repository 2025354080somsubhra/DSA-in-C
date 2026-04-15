// #include<stdio.h>

// int main() {
//     printf("\n Only stupids use C?");
//     display();
//     return 0;
// }

// display() {
//     printf("\n Fools too use C!");
//     main();
// }

// Factorial function

// #include<stdio.h>

// int factorial(int n) {
//     int fact = 1;
//     for(int i=1; i<=n; i++) {
//         fact *= i;
//     }
//     return fact;
// }

// int main() {
//     int a;
//     printf("Enter numeric value : ");
//     scanf("%d",&a);
//     printf("The factorial is : %d",factorial(a));
//     return 0;
// }

// Power Calculations

// #include<stdio.h>
// #include<math.h>

// int power(int base , int exponent) {
//     int c;
//     c = pow(base,exponent);
//     return c;
// }

// int main() {
//     int a,b;
//     printf("Enter the base value : ");
//     scanf("%d",&a);
//     printf("Enter the exponent value : ");
//     scanf("%d",&b);
//     printf("The Power is : %d",power(a,b));
// }

// #include <stdio.h>

// void intToRoman(int year) {
//     int val[]   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//     char *sym[] = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};

//     int i = 0;
//     while (year > 0) {
//         while (year >= val[i]) {
//             printf("%s", sym[i]);
//             year -= val[i];
//         }
//         i++;
//     }
// }

// int main() {
//     int year;

//     printf("Enter a year: ");
//     scanf("%d", &year);

//     printf("Roman equivalent: ");
//     intToRoman(year);
//     printf("\n");
//     return 0;
// }

// #include<stdio.h>

// int leap_year(int n) {
//     if(n%400 == 0 || n%4 == 0 || n%100 != 0) {
//         printf("The year is Leap Year");
//     } else {
//         printf("The year is not leap Year");
//     }
//     return n;
// }

// int main() {
//     int c;
//     printf("Enter a Year :");
//     scanf("%d",&c);
//     leap_year(c);
//     return 0;
// }

// #include <stdio.h>

// void primeFactors(int n) {
//     // Factor out 2
//     while (n % 2 == 0) {
//         printf("%d ", 2);
//         n /= 2;
//     }
    
//     // Factor out odd numbers
//     for (int i = 3; i * i <= n; i += 2) {
//         while (n % i == 0) {
//             printf("%d ", i);
//             n /= i;
//         }
//     }
    
//     // If n is still > 2, it must be prime
//     if (n > 2) {
//         printf("%d", n);
//     }
// }

// int main() {
//     int num;
//     printf("Enter a positive integer: ");
//     scanf("%d", &num);
//     printf("Prime factors: ");
//     primeFactors(num);
//     return 0;
// }

// #include<stdio.h>

// int isPrime(int n) {
//     int flag = 0;
//     if(n == 0 || n == 1) {
//         flag = 1;
//     }

//     for(int i = 2; i<= n/2; i++) {
//         if(n%i == 0) {
//             flag = 1;
//         }
//     }

//     if(flag == 0) {
//         printf("The number is Prime number");
//     } else {
//         printf("The number is not Prime number");
//     }
// }

// int main() {
//     int c;
//     printf("Enter a number : ");
//     scanf("%d",&c);
//     printf("%d",isPrime(c));
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, *ptr;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    ptr = (int*) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d",&ptr[i]);
    }
    printf("%d",ptr);
    return 0;
}