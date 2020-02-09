#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *((int *)a) < *((int *)b) ? -1 : 1; }

int main(void)
{
    int size, max;
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, size, sizeof(arr[0]), cmp);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > size - i)
        {
            printf("%d", size - i);
            return 0;
        }
    }

    // 特殊处理不符合的情况
    putchar('0');

    return 0;
}