#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);

void to_array(int a, char b[]);

int main()
{
    char num[5];
    int n;
    scanf("%d", &n);
    do
    {
        to_array(n, num);
        int max, min;

        qsort(num, 4, sizeof(char), cmp1);
        sscanf(num, "%d", &min);
        qsort(num, 4, sizeof(char), cmp2);
        sscanf(num, "%d", &max);
        
        printf("%04d - %04d = %04d\n", max, min, max - min);
        n = max - min;
    } while (n != 6174 && n != 0);


    return 0;
}

int cmp1(const void *a, const void *b)
{
    return *((char *)a) > *((char *)b) ? 1 : -1;
}

int cmp2(const void *a, const void *b)
{
    return *((char *)a) > *((char *)b) ? -1 : 1;
}

void to_array(int a, char b[])
{
    for (int i = 0; i < 4; i++)
    {
        b[i] = a % 10 + '0';
        a /= 10;
    }
}