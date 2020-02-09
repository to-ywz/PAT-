#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int matrixsize(int n);
int cmp(const void *a, const void *b) { return (*(int *)a) < (*(int *)b) ? 1 : -1; }

int arr[10000], Matrix[10000][1000];

int main(void)
{
    int size, n, m;
    scanf("%d", &size);
    m = matrixsize(size);
    n = size / m;

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, size, sizeof(arr[0]), cmp);

    int up = -1, down = m, left = -1, right = n;
    int i = 1, j = 0, index = 0;
    while (index < size)
    {
        //向右填充
        while (j < right)
        {
            Matrix[i][j] = arr[index++];
            j++;
        }
        up++;
        i++;
        j--;

        //向下填充
        while (i < down)
        {
            Matrix[i][j] = arr[index++];
            i++;
        }
        right--;
        i--;
        j--;

        //向左填充
        while (j > left)
        {
            Matrix[i][j] = arr[index++];
            j--;
        }
        down--;
        i--;
        j++;

        //向上填充
        while (i > up)
        {
            Matrix[i][j] = arr[index++];
            i--;
        }
        left++;
        i++;
        j++;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d%s", Matrix[i][j], n - 1 == j ? "" : " ");
        }
        putchar('\n');
    }

    return 0;
}

//矩阵的行
int matrixsize(int n)
{
    int m;
    m = (int)sqrt(n);
    if (m - sqrt(n) == 0)
    {
        return m;
    }
    m++;
    while (0 != n % m)
    {
        m++;
    }
    return m;
}
