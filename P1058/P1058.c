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
    int qunstionQun, studentQun, max = 0;

    scanf("%d %d", &studentQun, &qunstionQun);

    Qun Quntion[qunstionQun];

    for (int i = 0; i < qunstionQun; i++)
    {
        scanf("%d %d", &Quntion[i].mark, &Quntion[i].wrong);
        Quntion[i].wrong = 0;
        Quntion[i].Ans = AnsRecord();
    }

    for (int i = 0; i < studentQun; i++)
    {
        int score = 0;
        for (int j = 0; j < qunstionQun; j++)
        {
            while (getchar() != '(')
                ;
            if (Quntion[j].Ans == AnsRecord())
            {
                score += Quntion[j].mark;
            }
            else if (++Quntion[j].wrong > max)
            {
                max = Quntion[j].wrong;
            }
            while (getchar() != ')')
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
    char ch;
    int AnsQun, Ans = 0;
    scanf("%d", &AnsQun);
    for (int i = 0; i < AnsQun; i++)
    {
        while (' ' == (ch = getchar()))
            ;
        Ans |= 1 << (ch - 'a');
    }
    return Ans;
}