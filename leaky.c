#include <stdio.h>

int main()
{
    int bucket, rate, n, packet, stored = 0, i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter output rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter packet size: ");
        scanf("%d", &packet);

        if(stored + packet <= bucket)
            stored += packet;
        else
            printf("Packet dropped\n");

        if(stored >= rate)
        {
            stored -= rate;
            printf("Transmitted: %d\n", rate);
        }
        else
        {
            printf("Transmitted: %d\n", stored);
            stored = 0;
        }
    }

    return 0;
}