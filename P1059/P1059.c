#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int num);

int arr[10000];

int main(void)
{
    int size, index;
    scanf("%d", &size);

    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", &index);
        arr[index] = i + 1;
    }

    int num;
    scanf("%d", &num);
    for (size_t i = 0; i < num; i++)
    {
        scanf("%d", &index);

        if (-1 == arr[index])
        {
            printf("%04d: Checked\n", index);
            continue;
        }
        if (0 == arr[index])
        {
            printf("%04d: Are you kidding?\n", index);
            continue;
        }
        if (1 == arr[index])
        {
            printf("%04d: Mystery Award\n", index);
        }
        else
        {
            if (IsPrime(arr[index]))
            {
                printf("%04d: Minion\n", index);
            }
            else
            {
                printf("%04d: Chocolate\n", index);
            }
        }
        arr[index] = -1;
    }

    return 0;
}

int IsPrime(int num)
{
    // 0, 1特判
    if (num < 2)
    {
        return 0;
    }

    //两个较小数另外处理
    if (num == 2 || num == 3)
    {
        return 1;
    }

    //不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5)
    {
        return 0;
    }

    int tmp = sqrt(num);
    //在6的倍数两侧的也可能不是质数
    for (int i = 5; i <= tmp; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    //排除所有，剩余的是质数
    return 1;
}
