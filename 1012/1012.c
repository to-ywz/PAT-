#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int times;
    int Index = 0, _3times = 0, isRemainde1 = 0;
    int A[5] = {0};
    int temp = {0};
    int flag = 0;
    memset(A, -1, sizeof(A));
    scanf("%d", &times);

    while (times--)
    {
        scanf("%d", &temp);
        switch (temp % 5)
        {
        case 0:
            if (temp % 2 == 0)
            {
                A[0] += temp;
            }
            break;
        case 1:
            isRemainde1 = 1;
            if (0 == flag)
            {
                A[1] += temp;
            }
            else
            {

                A[1] -= temp;
            }
            flag = !flag;
            break;
        case 2:
            A[2]++;
            break;
        case 3:
            A[3] += temp;
            _3times++;
            break;
        case 4:
            if (A[4] < temp)
            {
                A[4] = temp;
            }
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (-1 == A[i])
        {
            if (1 == isRemainde1 && 1 == i)
            {
                A[i]++;
            }
            continue;
        }
        A[i]++;
    }

    for (int i = 0; i < 5; i++)
    {
        3 == i ? (0 == _3times ? printf(" N") : printf(" %.1lf", A[i] * 1.0 / _3times)) : (0 == i ? (-1 == A[i] ? printf("N") : printf("%d", A[i])) : (-1 == A[i] ? printf(" N") : printf(" %d", A[i])));
    }
    return 0;
}