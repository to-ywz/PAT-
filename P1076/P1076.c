#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    char str[4];

    while (~scanf("%s", str))
    {
        if (str[2] == 'T')
        {
            putchar("1234"[str[0] - 'A']);
        }
    }

    return 0;
}