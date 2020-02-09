#include <stdio.h>
#include <ctype.h>

int main()
{
    int keyboard[128] = {0};
    char str[81], ch;
    int i;
    scanf("%s\n", str);

    //第二次输入的字符串为进行计数
    while ('\n' != (ch = getchar()))
    {
        keyboard[toupper(ch)] = 1;
    }

    //完整比与统计数组比较，如果没有置1，且原字符串中含有该字符则代表按键损坏
    i = 0;
    while ('\0' != str[i])
    {
        ch = toupper(str[i]);
        if (keyboard[ch - '\0'] == 0)
        {
            putchar(ch);
            keyboard[ch - '\0'] = -1;
        }
        i++;
    }

    return 0;
}
