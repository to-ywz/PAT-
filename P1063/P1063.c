#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n;
    double a, b, max = 0.0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &a, &b);
        if (sqrt(a * a + b * b) > max)
        {
            max = sqrt(a * a + b * b);
        }
    }
    printf("%.2lf\n", max);

    return 0;
}