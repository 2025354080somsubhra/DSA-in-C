#include<stdio.h>

int main() {
    int marks[3];
    printf("physics :");
    scanf("%d",&marks[0]);

    printf("chem:");
    scanf("%d",&marks[1]);

    printf("math:");
    scanf("%d");

    printf("physics= %d,",marks[0]);
    printf("chem = %d,", marks[1]);
    printf("math = %d\n",marks[2]);
    return 0;
}

// Pointer Arithmetic
#include<stdio.h>

int main() {
    int age = 22;
    int *ptr = &age;
    
    int _age = 25;
    int *_ptr = &_age;

    printf("%u\n",ptr);
    ptr++;
    printf("%u\n",ptr);
    ptr--;
    printf("%u\n",ptr);
    ptr = ptr-ptr;
    printf("%u\n",ptr);

    ptr = &age;
    printf("%d\n",ptr == _ptr);

    return 0;
}

#include<stdio.h>

int main() {
    int marks[3];
    printf("physics :");
    scanf("%d",&marks[0]);

    printf("chem :");
    scanf("%d",&marks[1]);

    printf("math :");
    scanf("%d",&marks[2]);

    printf("physics =%d,",marks[0]);
    printf("chem = %d,",marks[1]);
    printf("math = %d\n", marks[2]);
    return 0;
}


#include <stdio.h>

int main() {
    int arr[5];  // Declare an array of size 5
    int i;

    // Input values using for loop
    for(i = 0; i < 5; i++) {
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Display values
    printf("You entered: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int search, i, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &search);

    // Linear search
    for(i = 0; i < 5; i++) {
        if(arr[i] == search) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;  // stop once found
        }
    }

    if(found == 0) {
        printf("Element not found in array\n");
    }

    return 0;
}

