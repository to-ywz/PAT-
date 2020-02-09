#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, index, sum = 0;
    int arr[10005] = {0};

    scanf("%d", &n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &index);
        arr[index]++;
    }

    size_t i = -1;
    while (0 == arr[++i] && i < 10001)
        ;
    sum += i;

    while (i++ < 10001)
    {
        while (arr[i]--)
        {
            sum += i;
            sum /= 2;
        }
    }

    printf("%d\n", sum);

    return 0;
}

/*
int compare(const void *a, const void *b) { return (*(int *)a) > (*(int *)b); }

int main(void)
{
    int n;

    scanf("%d", &n);
    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(arr[0]), compare);

    int sum = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        sum += arr[i];
        sum /= 2;
    }

    printf("%d\n", sum);

    return 0;
}
*/