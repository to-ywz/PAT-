#include <stdio.h>
#include <stdlib.h>

typedef struct QunData
{
    int mark;
    int wrong; //错误个数
    int Ans;   //位字段方式存储
} Qun;

int AnsRecord();

int main(void)
{
    char ch;
    int qunstionQun, studentQun, max = 0;

    scanf("%d %d", &studentQun, &qunstionQun);

    Qun Quntion[qunstionQun];

    for (int i = 0; i < qunstionQun; i++)
    {
        scanf("%d", &Quntion[i].mark);
        Quntion[i].wrong = 0;
        Quntion[i].Ans = AnsRecord();
    }

    for (int i = 0; i < studentQun; i++)
    {
        int score = 0;
        for (int j = 0; j < qunstionQun; j++)
        {
            while ('(' != (ch = getchar()))
                ;
            if (Quntion[i].Ans == AnsRecord())
            {
                score += Quntion[i].mark;
            }
            else if (++Quntion[i].wrong < max)
            {
                max = Quntion[i].wrong;
            }
            while ('(' != (ch = getchar()))
                ;
        }
        printf("%d\n", score);
    }

    if (0 == max)
    {
        printf("Too simple");
    }
    else
    {
        printf("%d", max);
        for (int i = 0; i < qunstionQun; i++)
        {
            if (Quntion[i].wrong == max)
            {
                printf(" %d", i + 1);
            }
        }
    }

    return 0;
}

//读入正确答案
int AnsRecord()
{
    int AnsQun, Ans = 0;
    scanf("%d", &AnsQun);
    char ch;
    for (int i = 0; i < AnsQun; i++)
    {
        while (' ' == (ch = getchar()))
        {
            Ans |= 1 << (ch - 'a');
        }
    }
    return Ans;
}