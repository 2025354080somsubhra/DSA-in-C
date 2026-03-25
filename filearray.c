#include <stdio.h>
#include <stdlib.h>

void read_data(long int *data, int n, char *file_name, int *count) {
    FILE *fp;
    int j = 0;
    long int index, value;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        *count = 0;
        return;
    }
    while (j < n) { 
        fscanf(fp, "%ld", &data[j]);
        j++;
    }
    fclose(fp);
    *count = j;
}

int main() {
    long int *data;
    int n, count = 0;
    printf("Enter the number of elements to be read: ");
    scanf("%d", &n);
    data = (long int *) malloc(n * sizeof(long int));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    read_data(data, n, "data.txt", &count);
    printf("Elements read from file:\n");
    for (int i = 0; i < count; i++) {
        printf("%ld\n", data[i]);
    }
    if (count < n) {
        printf("\nNote: Only %d elements were available in the file.\n", count);
    }

    free(data);
    return 0;
}