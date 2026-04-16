#include<stdio.h>

struct date {
    int dd;
    int mm;
    int yy;
};

typedef struct date d;

d b_date() {
    d a;
    printf("Enter your Birth date in (DD/MM/YY) : ");
    scanf("%d/%d/%d",&a.dd,&a.mm,&a.yy);
    return a;
}

d t_date() {
    d b;
    printf("Enter Today's date in (DD/MM/YY) : ");
    scanf("%d/%d/%d",&b.dd,&b.mm,&b.yy);
    return b;
}

int age_calc(d birth, d curr) {
    int age = curr.yy - birth.yy;
    if(curr.mm < birth.mm || curr.mm == birth.mm && curr.dd < birth.dd) {
        age --;
    }
    return age;
}

int main() {
    d dob, today;
    dob = b_date();
    today = t_date();
    int age = age_calc(dob,today);
    printf("Age of the person is %d years \n",age);
    return 0;
}


