#include<stdio.h>

int traverse(int DATA[], int LINK[], int START) {
    int PTR = START;
    while(PTR != -1) {
        printf("%d -> ",DATA[PTR]);
        PTR = LINK[PTR];
    }
}

int nodescount(int DATA[], int LINK[], int START) {
    int ptr;
    ptr = START;
    int count = 0;
    while(ptr != -1) {
        count++;
        ptr = LINK[ptr];
    }
    return count;
}

int main() {
    int data[11];
    int link[11];
    int start;
    start = 6;
    int n;
    
    data[6] = 10;
    link[6] = 3;
    
    data[3] = 50;
    link[3] = 10;
    
    data[10] = 30;
    link[10] = 7;
    
    data[7] = 20;
    link[7] = -1;
    
    traverse(data,link,start);
    
    n = nodescount(data,link,start);
    printf("\n Number of Nodes in Linked List is %d",n);
    return 0;
    
}