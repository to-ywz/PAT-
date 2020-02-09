#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double R1, P1, R2, P2;
    double A, B;

    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);

    A = R1 * R2 * (cos(P1 + P2));
    B = R1 * R2 * (sin(P1 + P2));

    printf("%.2lf%+.2lfi", (A < 0 && A > -0.005) ? 0 : A, (B < 0 && B > -0.005) ? 0 : B);

    return 0;
}