#include <stdio.h>
#include <stdlib.h>

int Mark[100];

int main(void)
{
    int n, score;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score);
        Mark[score]++;
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score);
        printf("%d%s", Mark[score], n - 1 == i ? "" : " ");
    }

    return 0;
}