#include <stdio.h>
#include <stdlib.h>
#define LIM 1000000007

int main(void)
{
    int P = 0, PA = 0, PAT = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if ('P' == ch)
        {
            P++;
            continue;
        }
        if ('A' == ch)
        {
            PA = (PA + P) % LIM;
            continue;
        }
        PAT = (PAT + PA) % LIM;
    }
    printf("%d", PAT);
    return 0;
}