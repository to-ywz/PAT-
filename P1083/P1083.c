#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, num;
    int Differences[10000] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        Differences[(i + 1 > num) ? (i - num + 1) : (num - i - 1)]++;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (Differences[i] >= 2)
        {
            printf("%d %d\n", i, Differences[i]);
        }
    }

    return 0;
}