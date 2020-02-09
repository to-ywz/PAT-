#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void compress(void);
void decompress(void);

int main(void)
{
    switch (getchar())
    {
    case 'C':
        while ('\n' != getchar())
            ;
        compress();
        break;
    case 'D':
        while ('\n' != getchar())
            ;
        decompress();
        break;
    }
    return 0;
}

void compress(void)
{
    int count = 1;
    char pre = getchar(), now;

    while (now = getchar())
    {
        if (now == pre)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                printf("%d", count);
            }
            putchar(pre);
            pre = now;
            count = 1;
        }
        if (now == '\n')
        {
            break;
        }
    }
}

void decompress(void)
{
    int count = 0;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isdigit(ch))
        { //Caculate the criculate times
            count = count * 10 + ch - '0';
        }
        else
        {
            if (0 == count)
            {
                count = 1;
            }
            for (int i = 0; i < count; i++)
            {
                putchar(ch);
            }
            count = 0;
        }
    }
}
