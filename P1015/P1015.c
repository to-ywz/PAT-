#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000
typedef struct
{
    int ID;          //考号
    int Moral_Mark;  //德分
    int Talent_Mark; //才分
} STData;

STData MTH_ST[MAXSIZE], MH_ST[MAXSIZE], MtTL_ST[MAXSIZE], MTL_ST[MAXSIZE];
//比较函数
int cmp(const void *a, const void *b);

int main(void)
{
    int Quantity, H_Level, L_Level;
    int count = 0, MTH_count = 0, MH_count = 0, MtTL_count = 0, MTL_count = 0;
    scanf("%d%d%d", &Quantity, &L_Level, &H_Level);

    for (int i = 0; i < Quantity; i++)
    {
        STData temp;
        scanf("%d %d %d", &temp.ID, &temp.Moral_Mark, &temp.Talent_Mark);
        if (temp.Moral_Mark >= L_Level && temp.Talent_Mark >= L_Level) //德分和才分高于最低线（前提）
        {
            count++;
            if (temp.Moral_Mark >= H_Level && temp.Talent_Mark >= H_Level) //德分和才分高于优秀线
            {
                MTH_ST[MTH_count++] = temp;
                continue;
            }
            if (temp.Moral_Mark >= H_Level && temp.Talent_Mark < H_Level) //德分高于优秀线
            {
                MH_ST[MH_count++] = temp;
                continue;
            }
            if (temp.Moral_Mark < H_Level && temp.Talent_Mark < H_Level && temp.Talent_Mark <= temp.Moral_Mark) //德分高于才分，且德分才分低于优秀线
            {
                MtTL_ST[MtTL_count++] = temp;
                continue;
            }
            MTL_ST[MTL_count++] = temp; //余下的
        }
    }

    //排序
    qsort(MTH_ST, MTH_count, sizeof(STData), cmp);
    qsort(MH_ST, MH_count, sizeof(STData), cmp);
    qsort(MtTL_ST, MtTL_count, sizeof(STData), cmp);
    qsort(MTL_ST, MTL_count, sizeof(STData), cmp);

    printf("%d\n", count);
    for (int i = 0; i < MTH_count; i++)
    {
        printf("%d %d %d\n", MTH_ST[i].ID, MTH_ST[i].Moral_Mark, MTH_ST[i].Talent_Mark);
    }
    for (int i = 0; i < MH_count; i++)
    {
        printf("%d %d %d\n", MH_ST[i].ID, MH_ST[i].Moral_Mark, MH_ST[i].Talent_Mark);
    }
    for (int i = 0; i < MtTL_count; i++)
    {
        printf("%d %d %d\n", MtTL_ST[i].ID, MtTL_ST[i].Moral_Mark, MtTL_ST[i].Talent_Mark);
    }
    for (int i = 0; i < MTL_count; i++)
    {
        printf("%d %d %d\n", MTL_ST[i].ID, MTL_ST[i].Moral_Mark, MTL_ST[i].Talent_Mark);
    }
    return 0;
}

//比较函数
int cmp(const void *a, const void *b)
{
    STData *Ptra = (STData *)a;
    STData *Ptrb = (STData *)b;
    int Total_Marka = Ptra->Moral_Mark + Ptra->Talent_Mark;
    int Total_Markb = Ptrb->Moral_Mark + Ptrb->Talent_Mark;

    if (Total_Marka != Total_Markb)
    {
        return Total_Markb - Total_Marka;
    }
    else
    {
        if (Ptra->Moral_Mark != Ptrb->Moral_Mark)
        {
            return Ptrb->Moral_Mark - Ptra->Moral_Mark;
        }
        else
        {
            return Ptra->ID - Ptrb->ID;
        }
    }
}
