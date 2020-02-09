#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1010

int main(void)
{
    int Number, Quotient, Remainder;
    char NumStr[MAXSIZE];

    scanf("%s%d", NumStr, &Number);

    Quotient = (NumStr[0] - '0') / Number;                          
    if ((Quotient != 0 && NumStr[1] != '\0') || '\0' == NumStr[1])//特判第一位小于除数输出0 和 只有一位数的情况
    {
        printf("%d", Quotient);
    }
    Remainder = (NumStr[0] - '0') % Number;

    //模拟带除法
    for (int i = 1; '\0' != NumStr[i]; i++)
    {
        Quotient = (Remainder * 10 + NumStr[i] - '0') / Number; //取商，每一次需要加上上一位的余数
        printf("%d", Quotient);                                 //直接输出，懒得存储了
        Remainder = (Remainder * 10 + NumStr[i] - '0') % Number;//取余，也需要加上上一位的余数
    }
    printf(" %d\n", Remainder);
    return 0;
}