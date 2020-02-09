#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int HouseQun, LimitDay;
    int Empty = 0, ReEmpty = 0;
    double LimitE;

    scanf("%d %lf %d", &HouseQun, &LimitE, &LimitDay);

    for (int i = 0; i < HouseQun; i++)
    {
        int ListenDay, count = 0;
        scanf("%d", &ListenDay);

        for (int j = 0; j < ListenDay; j++)
        {
            double E;
            scanf("%lf", &E);
            if (E < LimitE)
            {
                count++;
            }
        }
        if (count > ListenDay / 2 && ListenDay > LimitDay)
        {//条件一
            Empty++;
            continue;
        }
        if (count > ListenDay / 2)
        {//条件二
            ReEmpty++;
            continue;
        }
    }

    printf("%.1lf%% %.1lf%%", ReEmpty * 100.0 / HouseQun, Empty * 100.0 / HouseQun);

    return 0;
}