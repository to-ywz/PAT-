#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a > *(int *)b; }

int main()
{
    int n, max = 0, count = 0;
    scanf("%d", &n);
    int a[n], b[n], cn[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        cn[i] = a[i];
    }

    qsort(cn, n, sizeof(cn[0]), cmp);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        { //右边有比ta大的直接替换
            max = a[i];
        }
        if (max == a[i] && a[i] == cn[i])
        { //左边所有值的最大值为当前元素 && 如果排序前后位置没变
            b[count++] = a[i];
        }
    }

    printf("%d\n", count);

    if (0 == count)
    {
        printf("\n");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d%s", b[i], i == count - 1 ? "" : " ");
    }

    return 0;
}