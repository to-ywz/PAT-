#include <stdio.h>
#include <stdlib.h>

int GDB(int a, int b);

int main(void)
{
    int N1, M1, N2, M2, K, L = 1;

    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);

    //直接交叉相乘得出AB的大小
    if (N1 * M2 > N2 * M1)
    {
        L = N1;
        N1 = N2;
        N2 = L;
        L = M1;
        M1 = M2;
        M2 = L;
    }

    int count = 0;
    for (L = N1 * K / M1 + 1; N2 * K > M2 * L; L++)
    { //避开C的地板除、题目说不能取两边
        if (1 == GDB(L, K))
        {
            printf("%s%d/%d", count++ ? " " : "", L, K);
        }
    }

    return 0;
}

int GDB(int a, int b)
{
    for (int r; (r = a % b); a = b, b = r)
        ;
    return b;
}