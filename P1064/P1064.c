#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, m, sum = 0, count = 0;
    int friendID[37] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &m);
        sum = 0;
        while (m)
        {
            sum += m % 10;
            m /= 10;
        }
        if (0 == friendID[sum])
        {
            friendID[sum] = 1;
            count++;
        }
    }

    printf("%d\n", count);
    for (int i = 1; i < 37; i++)
    {
        if (friendID[i])
        {
            printf("%d%c", i, --count ? ' ' : '\0');
        }
    }

    return 0;
}