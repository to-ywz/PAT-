#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n, floor;
    char ch;
    scanf("%d %c", &n, &ch);

    floor = (int)sqrt((n + 1) / 2);

    //上三角
    for (int i = 0; i < floor; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (floor - i - 1) * 2 + 1; j++) //j小于的是等差数列求和公式每一层都增加2
        {
            printf("%c", ch);
        }
        putchar('\n');
    }
    //下梯形
    for (int i = 1; i < floor; i++)
    {
        for (int j = 1; j < floor - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (i)*2 + 1; j++) //道理同上，这里从1开始，下三角不打印第一行
        {
            printf("%c", ch);
        }
        putchar('\n');
    }

    printf("%d\n", n - (floor * floor * 2 - 1));    //等差求和得多余的

    return 0;
}