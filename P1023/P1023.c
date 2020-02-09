#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    //找到第一个非0的数字
    for (int i = 0; i < 10; i++)
    {
        if (arr[i])
        {
            printf("%d", i);
            arr[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        while (0 != arr[i])
        {
            printf("%d", i);
            arr[i]--;
        }
    }
    return 0;
}