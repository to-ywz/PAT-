#include <stdio.h>
#include <stdlib.h>

unsigned char color[128];

int main(void)
{
    char ch;
    int lack = 0, count = 0;

    //记录有的珠子及其数量
    while ((ch = getchar()) != '\n')
    {
        count++;
        color[ch]++;
    }

    //买不买
    while ((ch = getchar()) != '\n')
    {
        //检查有没有这种珠子
        if (color[ch])
        {
            count--; //减去需要的珠子。
            continue;
        }
        lack++; //记录缺少的珠子
    }

    if (lack)
    {
        printf("No %d\n", lack);
        return 0;
    }
    printf("Yes %d\n", count);

    return 0;
}
