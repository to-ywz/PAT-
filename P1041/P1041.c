#include <stdio.h>
#include <stdlib.h>

//数据结构体
struct Data
{
    //考号
    char ID[17];
    //试机座位号
    int Testnum;
    //考试座位号
    int FinallyNum;
} Student[1010];

int main(void)
{
    int studentnum, later_studentnum, sit;
    scanf("%d", &studentnum);

    for (int i = 0; i < studentnum; i++)
    {
        scanf("%s %d %d", &Student[i].ID, &Student[i].Testnum, &Student[i].FinallyNum);
    }

    scanf("%d", &later_studentnum);

    for (int i = 0; i < later_studentnum; i++)
    {
        scanf("%d", &sit);
        for (int j = 0; j < studentnum; j++)
        { //查找座位号
            if (sit == Student[j].Testnum)
            {
                printf("%s %d\n", Student[j].ID, Student[j].FinallyNum);
                break;
            }
        }
    }

    return 0;
}