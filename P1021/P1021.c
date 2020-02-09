#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

int main(void)
{
    char buffer[MAXSIZE];
    int numcont[10] = {0};

    scanf("%s", &buffer);                       //字符串方式读入数据

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        numcont[buffer[i] - '0']++;             //计数
    }

    for (int i = 0; i < 10; i++)
    {
        if (0 != numcont[i])
        {
            printf("%d:%d\n", i, numcont[i]);
        }
    }
    return 0;
}