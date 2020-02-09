#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 22

int main(void)
{
    char Base[MAXSIZE] = {0};
    char sA[MAXSIZE] = {0};
    char sB[MAXSIZE] = {0};
    char Sum[MAXSIZE] = {0};
    int LenA, LenB, LenBase, LenSum = 21, a, b, base;

    scanf("%s %s %s", Base, sA, sB);

    LenA = strlen(sA);
    LenB = strlen(sB);
    LenBase = strlen(Base);

    for (int i = 0; i < LenBase; i++)
    {
        //两个位不一样长添加前导0
        a = LenA > i ? sA[LenA - i - 1] - '0' : 0;
        b = LenB > i ? sB[LenB - i - 1] - '0' : 0;
        base = '0' == Base[LenBase - i - 1] ? 10 : Base[LenBase - i - 1] - '0';

        //计算和进位考虑到当前位有存在进位
        Sum[LenSum - i - 1] += a + b;
        Sum[LenSum - i - 2] += Sum[LenSum - i - 1] / base;
        Sum[LenSum - i - 1] = Sum[LenSum - i - 1] % base;
    }

    for (int i = 0; i < 21; i++)
    {
        Sum[i] += '0';
    }

    for (int i = 0; i < 21; i++)
    {
        if (Sum[i] != 0 && Sum[i] != '0')
        {
            puts(Sum + i);
            return 0;
        }
    }
    printf("0");

    return 0;
}