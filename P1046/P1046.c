#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, As, Aa, Bs, Ba;
    int Acount = 0, Bcount = 0;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d %d %d %d", &As, &Aa, &Bs, &Ba);

        if (Aa == As + Bs && Ba == As + Bs)
        {//去除都赢的平局
            continue;
        }
        if (Aa == As + Bs)
        {
            Bcount++;
            continue;
        }
        if (Ba == As + Bs)
        {
            Acount++;
            continue;
        }
    }

    printf("%d %d\n", Acount, Bcount);

    return 0;
}