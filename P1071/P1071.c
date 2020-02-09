#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T, K, n1, n2, b, t;

    scanf("%d %d", &T, &K);

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d\n", &n1, &b, &t, &n2);
        if (T <= 0)
        {
            printf("Game Over.\n");
            break;
        }
        if (t > T)
        {
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if ((n2 > n1 && 1 == b) || (n2 < n1 && 0 == b))
        {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        }
        else
        {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        }
    }
}