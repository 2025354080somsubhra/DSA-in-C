// Update Menu Driven Array Program

#include <stdio.h>


void inputArray(int arr[], int n)
{
    int i;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

int findSum(int arr[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int findMin(int arr[], int n)
{
    int i, min = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int findMax(int arr[], int n)
{
    int i, max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int findAvg(int arr[], int n)
{
    int sum = findSum(arr, n);
    return sum / n;
}

int menu()
{
    int choice;
    printf("MENU \n");
    printf("1. Sum \n");
    printf("2. Minimum \n");
    printf("3. Maximum \n" );
    printf("4. Average \n");
    printf("5. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int arr[100], n, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    inputArray(arr, n);   

    do
    {
        choice = menu();

        switch (choice)
        {
            case 1:
                result = findSum(arr, n);
                printf("Sum = %d", result);
                break;

            case 2:
                result = findMin(arr, n);
                printf("Minimum = %d", result);
                break;

            case 3:
                result = findMax(arr, n);
                printf("Maximum = %d", result);
                break;

            case 4:
                result = findAvg(arr, n);
                printf("Average = %d", result);
                break;

            case 5:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice! Try again.");
        }

    } while (choice != 5);

    return 0;
}
