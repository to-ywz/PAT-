#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char Lowbit[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char Higbit[][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

//地球语言->火星文
void Translate_EtoM(int num);
//火星文->地球语言
int Translate_MtoE(char *s);

int main(void)
{
    char language[11];
    int n;

    scanf("%d\n", &n); //懒得用getchar来吞回车了

    while (n--)
    {
        fgets(language, 11, stdin); //代替gets的函数，c++的cin多好啊
        int num;
        if (isalpha(language[0]))
        {                                                    //题目说过范围再0~169，所以火星文的最大长度为2
            num = Translate_MtoE(strtok(language, " \n"));   //截取第一段
            num = num + Translate_MtoE(strtok(NULL, " \n")); //截取第二段，NULL是为让strtok从上次停止的地方开始
            printf("%d\n", num);
        }
        else
        {
            sscanf(language, "%d", &num); //指定输入流读入
            Translate_EtoM(num);
        }
    }

    return 0;
}

void Translate_EtoM(int num)
{
    if (num / 13 && num % 13)
    {
        printf("%s %s\n", Higbit[num / 13 - 1], Lowbit[num % 13]);
        return;
    }
    if (num / 13 && 0 == num % 13)
    {
        printf("%s\n", Higbit[num / 13 - 1]);
        return;
    }

    printf("%s\n", Lowbit[num % 13]);
}

int Translate_MtoE(char *s)
{
    if (s != NULL)
    {
        for (int i = 0; i < 13; i++)
        { //从低位中寻找字符串
            if (strcmp(s, Lowbit[i]) == 0)
            {
                return i;
            }
        }
        for (int i = 1; i < 13; i++)
        { //从高位中寻找字符串
            if (strcmp(s, Higbit[i - 1]) == 0)
            {
                return i * 13;
            }
        }
    }
    return 0;
}