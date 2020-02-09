#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

int SumMark[MAXSIZE];

int main(void)
{
    int n, Index, Mark;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &Index, &Mark);
        SumMark[Index] += Mark;
    }

    int MAX = -1;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (SumMark[i] > SumMark[MAX])
        {
            MAX = i;
        }
    }

    printf("%d %d\n", MAX, SumMark[MAX]);

    return 0;
}