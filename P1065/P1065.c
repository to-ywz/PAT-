#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOG -2
#define SINGLE -3

int Couple[100000];

int main(void)
{
    int count = 0, n, IDL, IDR;
    memset(Couple, -1, sizeof(Couple));

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    { //形成夫妻映射
        scanf("%d %d", &IDL, &IDR);
        Couple[IDL] = IDR;
        Couple[IDR] = IDL;
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    { //读取参加聚会的ID
        scanf("%d", &IDL);
        if (Couple[IDL] >= 0)
        {                      //如果是撒狗粮的无论是一直还是两只先都变狗
            Couple[IDL] = DOG; //暂时让ta变成单身狗
        }
        else
        { //余下的就真的是狗了
            Couple[IDL] = SINGLE;
            count++;
        }
    }

    for (size_t i = 0; i < 100000; i++)
    { //这一部分用于实现给撒狗粮没撒成的在这次聚会中变成真狗
        if (Couple[i] >= 0 && DOG == Couple[Couple[i]])
        { //如果当前ID能够追寻到另一个ID就代表被追寻到的肯定是没撒成狗粮的
            Couple[Couple[i]] = SINGLE;
            count++;
        }
    }

    printf("%d\n", count);
    for (size_t i = 0; i < 100000; i++)
    { //只要是SINGLE就是是单身，管ta来干什么的，兄弟姐妹们，抢啊
        if (SINGLE == Couple[i])
        {
            printf("%05d%s", i, --count ? " " : "");
        }
    }

    return 0;
}