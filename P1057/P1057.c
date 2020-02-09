#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int sum = 0, count1 = 0, count0 = 0;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            sum += tolower(ch) - 'a' + 1;
        }
    }

    while (sum)
    {
        if (sum & 0x01)
        {
            count1++;
        }
        else
        {
            count0++;
        }
        sum >>= 1;
    }

    printf("%d %d", count0, count1);

    return 0;
}