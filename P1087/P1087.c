#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int premax;
    int nowmax = -1, count = 0;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        premax = i / 2 + i / 3 + i / 5;
        if (premax > nowmax)
        {
            count++;
        }
        nowmax = premax;
    }

    printf("%d", count);

    return 0;
}