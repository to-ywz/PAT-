#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100005
#define MAX(a, b) ((a) > (b) ? (a) : (b)) //最大值的宏内联函数
int cmp(void const *a, void const *b) { return (*(long *)a) > (*(long *)b) ? 1 : -1; }

int main(void)
{
    int num = 0;
    long size, P;
    long array[MAXSIZE];

    scanf("%ld %ld", &size, &P);

    for (int i = 0; i < size; i++)
    {
        scanf("%ld", &array[i]);
    }
    //升序
    qsort(array, size, sizeof(array[0]), cmp);

    
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        int j = cnt;                    //将前面算过的数全部屏蔽掉
        while (j++ < size)
        {
            if (array[j] > array[i] * P)
            {
                break;
            }
        }
        num = MAX(num, j - i - 1);
        cnt = j;
    }

    printf("%d\n", num);

    return 0;
}