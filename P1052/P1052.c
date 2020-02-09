#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    char xStr_3[3][10][5] = {0};
    int Index[5];
    int n, j;

    for (int i = 0; i < 3; i++)
    {
        j = 0;
        while ('\n' != (ch = getchar()))
        {
            if ('[' == ch)
            {
                scanf("%[^]]", xStr_3[i][j++]);
            }
        }
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &Index[j]);
        }
        if (Index[0] > 0 && Index[0] <= 10 
        && *xStr_3[0][--Index[0]] && Index[1] > 0
        && Index[1] <= 10 && *xStr_3[1][--Index[1]] 
        && Index[2] > 0 && Index[2] <= 10 
        && *xStr_3[2][--Index[2]] && Index[3] > 0 
        && Index[3] <= 10 && *xStr_3[1][--Index[3]] 
        && Index[4] > 0 && Index[4] <= 10 && *xStr_3[0][--Index[4]])
        {
            printf("%s(%s%s%s)%s\n", xStr_3[0][Index[0]], xStr_3[1][Index[1]]
            , xStr_3[2][Index[2]], xStr_3[1][Index[3]], xStr_3[0][Index[4]]);
        }
        else
        {
            printf("Are you kidding me? @\\/@\n");
        }
    }

    return 0;
}

/*
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3

*/