// #include<stdio.h>

// int main() {
//     int age = 22;
//     int *ptr = &age;
//     int _age = &ptr;

//     printf("%u\n",&ptr);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

void shortName(char name[])
{
    int i, len = strlen(name);
    printf("Short Name: %c", name[0]);
    for(i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            printf("%c ", name[i+1]);  
            break;
        }
    }
    int spaceCount = 0;
    for(i = 0; i < len; i++)
    {
        if(name[i] == ' ')
            spaceCount++;

        if(spaceCount == 2)
        {
            printf("%s", &name[i+1]);  
            break;
        }
    }
}

int main()
{
    char name[100];
    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  
    shortName(name);
    return 0;
}


