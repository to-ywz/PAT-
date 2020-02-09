#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//统计英文字母个数的数组
int count[26];

int main(void)
{
    char ch;
    int max = 0; //存储最大值索引

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        { //要求输出英文字母
            count[(int)tolower(ch) - 96]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > count[max])
        {
            max = i;
        }
    }

    printf("%c %d\n", (char)(max + 96), count[max]);

    return 0;
}