#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, x, y, max = 0, min = 0;
    scanf("%d", &n);

    int Distance[n], ID[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &ID[i], &x, &y);
        Distance[i] = x * x + y * y;
        if (Distance[max] < Distance[i])
        {
            max = i;
        }
        if (Distance[min] > Distance[i])
        {
            min = i;
        }
    }

    printf("%04d %04d", ID[min], ID[max]);

    return 0;
}