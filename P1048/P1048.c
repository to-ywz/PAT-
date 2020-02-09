#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str);

int main(void)
{
    int LenB, LenA, temp;
    char strA[100], strB[100], ans[100] = {0};
    scanf("%s %s", strA, strB);

    LenA = strlen(strA);
    LenB = strlen(strB);
    //判断AB
    int Len = LenA > LenB ? LenA : LenB;
    
    //反转数组
    reverse(strA);
    reverse(strB);

    for (int i = 0; i < Len; i++)
    {
        //自制补0(つ﹏⊂)
        int numA = i < LenA ? strA[i] - '0' : 0;
        int numB = i < LenB ? strB[i] - '0' : 0;

        if (i % 2 == 0)
        {
            //奇数处理
            int temp = (numA + numB) % 13;
            if (temp == 10)
            {
                ans[i] = 'J';
            }
            else if (temp == 11)
            {
                ans[i] = 'Q';
            }
            else if (temp == 12)
            {
                ans[i] = 'K';
            }
            else
            {
                ans[i] = temp + '0';
            }
        }
        else
        {
            //偶数处理
            int temp = numB - numA;
            if (temp < 0)
            {
                temp += 10;
            }
            ans[i] = temp + '0';
        }
    }
    //反转答案(懒得动脑子)
    reverse(ans);
    puts(ans);

    return 0;
}

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        int temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}