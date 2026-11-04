#include <stdio.h>

int main()
{
    int n, w, i, j, lost;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter lost frame number (0 for no loss): ");
    scanf("%d", &lost);

    i = 1;

    while(i <= n)
    {
        printf("\nSending Window:\n");

        for(j = i; j < i + w && j <= n; j++)
        {
            printf("Sending Frame %d\n", j);
        }

        if(lost >= i && lost < i + w)
        {
            printf("\nFrame %d lost!\n", lost);

            printf("Go-Back-N Retransmission:\n");

            for(j = lost; j < i + w && j <= n; j++)
            {
                printf("Retransmitting Frame %d\n", j);
            }

            lost = 0;
        }

        printf("Acknowledgement received\n");

        i = i + w;
    }

    printf("\nAll frames transmitted successfully.");

    return 0;
}