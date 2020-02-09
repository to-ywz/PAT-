#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int Galleon, Sickle, Knut;
    int price = 0, wealth = 0, surplus = 0, Negative = 0;
    
    //进行Kunt转化
    scanf("%d.%d.%d", &Galleon, &Sickle, &Knut);
    price += (Galleon * 17 + Sickle) * 29 + Knut;

    scanf("%d.%d.%d", &Galleon, &Sickle, &Knut);
    wealth += (Galleon * 17 + Sickle) * 29 + Knut;

    //得出结余
    surplus = wealth - price;

    if (surplus < 0)
    {
        surplus *= -1;//取绝对值
        Negative = 1;//记录符号
    }

    //根据货币转换机制输出
    printf("%s%d.%d.%d", 1 == Negative ? "-" : "", surplus / 29 / 17, surplus / 29 % 17, surplus % 29);

    return 0;
}