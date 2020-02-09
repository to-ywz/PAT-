#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    double temp, sum = 0.0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &temp);
        sum += temp * (i + 1) * (n - i);
    }

    printf("%.2lf\n", sum);

    return 0;
}