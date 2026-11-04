#include <stdio.h>

int main()
{
    int bucket, rate, tokens, n, packet, i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter token rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    tokens = bucket;

    for(i = 1; i <= n; i++)
    {
        printf("Enter packet size: ");
        scanf("%d", &packet);

        tokens += rate;

        if(tokens > bucket)
            tokens = bucket;

        if(packet <= tokens)
        {
            printf("Packet transmitted\n");
            tokens -= packet;
        }
        else
            printf("Packet dropped\n");

        printf("Remaining tokens: %d\n", tokens);
    }

    return 0;
}