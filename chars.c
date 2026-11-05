#include <stdio.h>

int main()
{
    char data[100];
    int i;

    printf("Enter the data: ");
    scanf("%s", data);

    printf("Stuffed Frame: DLE STX ");

    for(i = 0; data[i] != '\0'; i++)
    {
        if(data[i] == 'D')
            printf("DLE ");

        printf("%c", data[i]);
    }

    printf(" DLE ETX");

    return 0;
}