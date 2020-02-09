#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[32] = {0};
    int A, B, C, D, count = 0;
    scanf("%d %d %d", &A, &B, &D);
    C = A + B;

    if (0 == C)
    {
        count = 1;
    }

    while (0 != C)
    {
        arr[count++] = C % D;
        C /= D;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    return 0;
}