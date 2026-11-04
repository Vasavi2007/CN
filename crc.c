#include <stdio.h>
#include <string.h>

char data[100], divisor[30], temp[100], rem[30];

int main()
{
    int i, j;
    int dataLen, divLen;

    printf("Enter Data: ");
    scanf("%s", data);

    printf("Enter Generator Polynomial: ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divLen = strlen(divisor);

    // Append zeros
    for(i = 0; i < divLen - 1; i++)
        data[dataLen + i] = '0';

    data[dataLen + divLen - 1] = '\0';

    strcpy(temp, data);

    // CRC Division
    for(i = 0; i <= strlen(data) - divLen; i++)
    {
        if(temp[i] == '1')
        {
            for(j = 0; j < divLen; j++)
            {
                if(temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get remainder
    for(i = 0; i < divLen - 1; i++)
        rem[i] = temp[strlen(data) - divLen + 1 + i];

    rem[divLen - 1] = '\0';

    printf("\nCRC Remainder : %s", rem);

    // Form Codeword
    dataLen = strlen(data);
    for(i = 0; i < divLen - 1; i++)
        data[dataLen - divLen + 1 + i] = rem[i];

    printf("\nCodeword      : %s\n", data);

    return 0;
}