#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char data1[40];
    char data2[40];
    int n, count = 0;
    double temp, sum = 0.0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", data1);
        sscanf(data1, "%lf", &temp);
        sprintf(data2, "%.2lf", temp);

        //合法小数判断
        int flag = 1;
        for (int j = 0; data1[j] != '\0'; j++)
        {
            if (data1[j] != data2[j])
            {
                flag = 0;
                break;
            }
        }
        //整数合法性
        if (0 == flag || temp < -1000 || temp > 1000)
        {
            printf("ERROR: %s is not a legal number\n", data1);
            continue;
        }
        sum += temp;
        count++;
    }

    if (0 == count)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else
    {
        printf("The average of %d number%s is %.2f", 1 == count ? 1 : count, 1 == count ? "" : "s", 1 == count ? sum : sum / count);
    }

    return 0;
}