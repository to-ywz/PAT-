#include <stdio.h>
#include <ctype.h>
#include <ma
int main()
{
    int keyboard[128] = {0};
    char ch;

    while ((ch = getchar()) != '\n')
    {
        keyboard[toupper(ch)] = -1;
    }

    while ((ch = getchar()) != '\n')
    {
        //（键盘本身损坏）||（输出大写字母 && 上档键损坏
        if (-1 == (keyboard[toupper(ch)]) || (isupper(ch) && -1 == keyboard['+' - '\0']))
        {
            continue;
        }
        putchar(ch);
    }

    printf("\n");

    return 0;
}