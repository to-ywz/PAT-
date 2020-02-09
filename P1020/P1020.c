#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

typedef struct
{
    double value;
    double Quantity;
    double sValue;
} Cake;

int cmp(const void *a, const void *b);

int main(void)
{
    int CakeKind, Demand;
    double Profit = 0;
    Cake cake[MAXSIZE] = {0, 0};

    scanf("%d %d", &CakeKind, &Demand);

    for (int i = 0; i < CakeKind; i++)
    {
        scanf("%lf", &cake[i].Quantity);
    }

    for (int i = 0; i < CakeKind; i++)
    {
        scanf("%lf", &cake[i].value);
    }

    for (int i = 0; i < CakeKind; i++)
    {
        cake[i].sValue = cake[i].value / cake[i].Quantity;
    }

    qsort(cake, MAXSIZE, sizeof(Cake), cmp);

    for (int i = 0; i < CakeKind; i++)
    {
        if (0 == Demand)
        {
            break;
        }
        if (cake[i].Quantity <= Demand)
        {
            Profit += cake[i].value;
            Demand -= cake[i].Quantity;
        }
        else
        {
            Profit += (Demand / cake[i].Quantity) * cake[i].value;
            Demand = 0;
        }
    }

    printf("%.2lf", Profit);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(Cake *)a).sValue < (*(Cake *)b).sValue ? 1 : -1;
}