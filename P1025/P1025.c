#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100011
typedef struct
{
    int Address;
    int Data;
    int Next;
} ListNode;

int main(void)
{
    int head, n, K;
    ListNode List[MAXSIZE];
    scanf("%d%d%d", &head, &n, &K);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &List[i].Address, &List[i].Data, &List[i].Next);
    }

    //线找到首地址
    for (int i = 0; i < n; i++)
    {
        if (List[i].Address == head)
        {
            ListNode temp = List[i];
            List[i] = List[0];
            List[0] = temp;
            break;
        }
    }

    //整理链表顺序
    for (int i = 0; i < n; i++)
    {
        if (-1 == List[i].Next)
        {
            n = i + 1;
            break;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (List[j].Address == List[i].Next)
            {
                ListNode temp = List[i + 1];
                List[i + 1] = List[j];
                List[j] = temp;
                break;
            }
        }
    }

    //取出需要交换的次数
    int Quotient = n / K;

    for (int i = 0; i < Quotient; i++)
    {
        for (int j = 0; j < K / 2; j++)
        {//因为不是和冒泡那样的连续赋值而是交换所以只要一般的的次数

            //交换
            ListNode temp = List[K * i + j];
            List[K * i + j] = List[K * (i + 1) - j - 1];
            List[K * (i + 1) - j - 1] = temp;
        }
    }

    //重写地址
    for (int i = 0; i < Quotient * K; i++)
    {
        List[i].Next = List[i + 1].Address;
    }
    List[n - 1].Next = -1;

    
    for (int i = 0; i < n; i++)
    {
        if (-1 == List[i].Next)
        {//特殊处理-1;
            printf("%05d %d %d\n", List[i].Address, List[i].Data, List[i].Next);
            continue;
        }
        printf("%05d %d %05d\n", List[i].Address, List[i].Data, List[i].Next);
    }

    return 0;
}

/*
00100 10 2                   00100 10 2                     00100 10 4
0000 4 99999                 0000 4 99999                    0000 4 99999
00100 1 12309                00100 1 12309                   00100 1 12309
68237 6 -1                   68237 6 89001                   68237 6 89001
33218 3 00000                33218 3 00000                   33218 3 00000
99999 5 68237                99999 5 68237                   99999 5 68237
12309 2 33218                12309 2 33218                   12309 2 33218
89001 7 89100                89001 7 89100                   89001 7 89100
89100 8 89200                89100 8 89200                   89100 8 89200
89200 9 89300                89200 9 89300                   89200 9 89300
89300 10 89400               89300 10 -1                     89300 10 -1
*/