#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pixel, n, m, A, B, replacepx;
    scanf("%d %d %d %d %d", &n, &m, &A, &B, &replacepx);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &pixel);
            if (pixel > B || pixel < A)
            {
                printf("%03d%s", pixel, m - 1 == j ? "\n" : " ");
                continue;
            }
            printf("%03d%s", replacepx, m - 1 == j ? "\n" : " ");
        }
    }

    return 0;
}