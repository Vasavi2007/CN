#include <stdio.h>
#include <string.h>

int main()
{
    char data[100];
    int i, count;

    printf("Enter the data: ");
    scanf("%s", data);

    count = strlen(data) + 1;

    printf("Character Count Frame: ");
    printf("%d", count);

    for(i = 0; data[i] != '\0'; i++)
    {
        printf("%c", data[i]);
    }

    return 0;
}