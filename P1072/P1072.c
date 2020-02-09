#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K, forbidden[10000] = {0}, temp, count = 0, Scount = 0;
    int Ans[11], n;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++)
    {
        scanf("%d", &temp);
        forbidden[temp] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        char Name[5];
        scanf("%s %d", Name, &n);
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            if (forbidden[temp])
            {
                Ans[cnt++] = temp;
                count++;
            }
        }
        if (cnt)
        {
            Scount++;
            printf("%s: ", Name);
            for (int j = 0; j < cnt; j++)
            {
                printf("%04d%s", Ans[j], j == cnt - 1 ? "\n" : " ");
            }
        }
    }
    printf("%d %d", Scount, count);

    return 0;
}