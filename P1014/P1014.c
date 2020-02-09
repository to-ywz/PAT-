#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *WEEKDAYS[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void)
{
    int count = 0;
    int PassWord[3] = {-1, -1, -1};
    char buf[4][61];

    for (int i = 0; i < 4; i++)
    {
        scanf("%s", buf[i]);
    }

    int i = 0, j = 0;

    while (('\0' != buf[0][i] && '\0' != buf[1][j]) || ('\0' != buf[2][i]))
    {
        if (1 == count && buf[0][i] == buf[1][j])
        {
            if ('0' <= buf[0][i] && '9' >= buf[0][i])
            {
                PassWord[count++] = buf[0][i] - '0';
            }
            else if ('A' <= buf[0][i] && 'N' >= buf[0][i])
            {
                PassWord[count++] = buf[0][i] - 'A' + 10;
            }
        }
        if (0 == count && buf[0][i] == buf[1][j])
        {
            if ('A' <= buf[0][i] && 'G' >= buf[0][i])
            {
                PassWord[count++] = buf[0][i] - 'A';
            }
        }
        if (-1 == PassWord[2] && buf[2][i] == buf[3][j] && ((buf[2][i] >= 'a' && buf[2][i] <= 'z') || (buf[2][i] >= 'A' && buf[2][i] <= 'Z')))
        {
            PassWord[2] = i;
        }
        i++;
        j++;
    }

    printf("%s %02d:%02d\n", WEEKDAYS[PassWord[0]], PassWord[1], PassWord[2]);
    return 0;
}
/*
3485djZAxh4hhZN
2984akZAkkkkgZNdsb
s&hgsadk
d&Hysavnm
*/