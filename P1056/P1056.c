#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, sum = 0;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += (arr[i] * 10 + arr[j]);
            sum += (arr[j] * 10 + arr[i]);
        }
    }

    printf("%d\n", sum);

    return 0;
}