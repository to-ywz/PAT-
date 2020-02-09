#include <stdio.h>
#include <stdlib.h>
#define CLK_TCK 100

int main(void)
{
    int H, M, STime, ETime;
    double Time, S;
    scanf("%d %d", &STime, &ETime);

    Time = ETime - STime;
    Time /= CLK_TCK;

    H = Time / 3600;
    Time -= H * 3600;
    M = Time / 60;
    Time -= M * 60;
    S = Time;

    printf("%02d:%02d:%02.0f", H, M, S);

    return 0;
}