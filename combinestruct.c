#include<stdio.h>
#include<string.h>

enum dt {
    INTEGER, FLOAT, CHARACTER, STRING
};

union data {
    int i;
    float f;
    char c;
    char str[100];   
};

struct datatype {
    enum dt type;
    union data value;  
};

typedef struct datatype sdt;

int option_list() {
    int ch;
    printf("Select Data Type:\n");
    printf("1 Integer\n");
    printf("2 Float\n");
    printf("3 Character\n");
    printf("4 String\n");
    printf("Enter your Choice (1-4): ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    sdt d;
    int ch;

    ch = option_list();    
    d.type = ch - 1;        

    switch(d.type) {

        case INTEGER:
            printf("Enter integer value: ");
            scanf("%d", &d.value.i);
            break;

        case FLOAT:
            printf("Enter float value: ");
            scanf("%f", &d.value.f);
            break;

        case CHARACTER:
            printf("Enter character value: ");
            scanf(" %c", &d.value.c);
            break;

        case STRING:
            printf("Enter string value: ");
            scanf("%s", d.value.str);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\nStored Value:\n");

    switch (d.type) {
        case INTEGER:
            printf("Integer = %d\n", d.value.i);
            break;

        case FLOAT:
            printf("Float = %.2f\n", d.value.f);
            break;

        case CHARACTER:
            printf("Character = %c\n", d.value.c);
            break;

        case STRING:
            printf("String = %s\n", d.value.str);
            break;
    }

    return 0;
}