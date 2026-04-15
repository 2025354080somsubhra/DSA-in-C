#include<stdio.h>
#include<string.h>

struct Student {
    int id;
    int marks;
    char name[100];
};

typedef struct Student stu; // typedef is used rename a datatype in short form
// union can access one data (shared memory), while structure can access all data types at one go

int main() {
    stu a,b,c;
    a.id = 001;
    b.id = 002;
    c.id = 003;
    a.marks = 100;
    b.marks = 50;
    c.marks = 80;
    strcpy(a.name,"Somsubhra Chatterjee");

    printf("My name is %s",a.name);
    return 0;
}