#include <stdio.h>
#include <stdlib.h>

const char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

int main(void)
{
    int n, cont = 0;
    char buf[19];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        int sum = 0;
        for (int j = 0; '\0' != buf[j]; j++)
        {
            if (j < 17)
            {
                if (buf[j] >= '0' && buf[j] <= '9')
                {
                    sum += (buf[j] - '0') * weight[j];
                    continue;
                }
                printf("%s\n", buf);
                cont++;
                break;
            }
            if (j == 17)
            {
                if (buf[j] != M[sum % 11])
                {
                    printf("%s\n", buf);
                    cont++;
                    break;
                }
                continue;
            }
        }
    }
    if (0 == cont)
    {
        printf("All passed\n");
    }
    return 0;
}
