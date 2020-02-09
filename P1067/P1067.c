#include <stdio.h>
#include <stdlib.h>

int PasswordSum(int mode);

char Word[23] = "\0";

int main(void)
{
    char ch;
    int n, i, Password, sum = 0;

    Password = PasswordSum(0);

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        sum = PasswordSum(1);
        if (((int)'#') == sum)
        {
            break;
        }
        if (sum == Password)
        {
            printf("Welcome in\n");
            break;
        }
        printf("Wrong password: %s\n", Word);
    }

    if (i == n)
    {
        printf("Account locked");
    }

    return 0;
}

// 错误无输出，输出需要字符串，锁机制未检测
int PasswordSum(int mode)
{
    char ch, BKCh;
    int i = 0, sum = 0;

    BKCh = 1 == mode ? '\n' : ' ';

    while (BKCh != (ch = getchar()))
    {
        sum += ch - '\0';
        Word[i++] = ch;
    }
    Word[i] = '\0';

    return sum;
}

/*
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#

*/