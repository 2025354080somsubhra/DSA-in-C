#include <stdio.h>

// Function to calculate and print average of three numbers
void average_of_three(int a, int b, int c) {
    float avg = (a + b + c) / 3.0;  // use 3.0 to ensure float division
    printf("Average of the three numbers is: %.2f\n", avg);
}

int main() {
    int x, y, z;

    // Example input
    printf("Enter three numbers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Call the function
    average_of_three(x, y, z);

    return 0;
}

#include<stdio.h>

void si_calc(float p, float r, int t) {
    float si = p*r*t;
    float div = si/100;
    printf("The Simple Interest is : %.2f",div);
}

int main() {
    float x,y;
    int z;
    printf("Enter the Principal Amount :");
    scanf("%f",&x);
    printf("Enter the Rate of Interest :");
    scanf("%f",&y);
    printf("Enter the Time Period in Years :");
    scanf("%d",&z);

    si_calc(x,y,x);

    return 0;
}   

#include<stdio.h>
#include<math.h>

int isPrime(int n) {
    if(n <= 1) return 0;
    for(int i=2; i<= sqrt(n); i++) {
        if( n%i == 0) return 0;
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number:");
    scanf("%d",&num);

    if(isPrime(num)) {
        printf("%d is a prime number\n",num);
    } else {
        printf("%d is not a prime number\n",num);
    }

    return 0;
}

#include<stdio.h>

int main() {
    int marks[3] = {1,2,3};
    printf("%d",marks[3]);
    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, n = 0;
    double result = 0.0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Count number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    // Compute sum of digits raised to power n
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    // Check Armstrong condition
    if ((int)result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

#include <stdio.h>

int isPrime(int n) {
    int flag = 1;  // assume prime initially

    if (n <= 1) {
        flag = 0;  // not prime
    } else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = 0;  // found a divisor, not prime
                break;     // exit loop early
            }
        }
    }

    return flag;  // 1 means prime, 0 means not prime
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}


#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
