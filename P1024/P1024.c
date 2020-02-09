#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

int main(void)
{
    int Integer, Exponent, count = 0;
    char Decimal[MAXSIZE];

    scanf("%d.%[0-9]E%d", &Integer, &Decimal, &Exponent); //正则表达式输入（瞎逼逼，就是格式化输入，呃用了一点点正则）
    printf("%s", Integer < 0 ? "-" : "");                 //处理正负号，预防小于 0 的 小数
    while (Exponent++ < 0)                                //如果指数小于0，先输出指数的个数
    {
        printf("0%s", count++ == 0 ? "." : "");
    }
    Exponent--;                 //0 -> Exponent, 所以-1
    printf("%d", abs(Integer)); //输出第一位
    for (int i = 0; i < strlen(Decimal) || i < Exponent; i++)
    { //0 -> Exponent,两个终止条件一个是保留小数位数，一个是整数补齐科学计数法的小数部分0不够补0

        printf("%s%c", i == Exponent && !count ? "." : "", i < strlen(Decimal) ? Decimal[i] : '0');
    }

    return 0;
}
