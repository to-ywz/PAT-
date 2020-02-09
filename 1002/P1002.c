#include <stdio.h>
#include <string.h>

//数字的字符数组
const char num[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{

    char str[110];
    scanf("%s", str);
    
    //求和
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += str[i] - '0';
    }

    //取各个位数上的数
    int i = 0;
    while (sum != 0)
    {
        str[i++] = sum % 10 + '0';
        sum /= 10;
    }
    str[i] = '\0';//隔断字符串

    //输出
    int len = strlen(str);
    for (i = len - 1; i >= 0; i--)
    {
        i == 0 ? printf("%s\n", num[str[i] - '0']) : printf("%s ", num[str[i] - '0']);
    }
    return 0;
}