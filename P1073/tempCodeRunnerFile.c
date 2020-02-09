#include <stdio.h>

#define MAX_M 100
#define MAX_OPTIONS 5

typedef struct
{
    int Ans;
    int Mark;
    int WAnswer[5];
} Qun;

int readanswer();

int main(void)
{
    Qun qunstion[MAX_M];
    int wrong_ans[MAX_M] = {0};
    int N, M, wrong_count_max = 0;

    scanf("%d %d", &N, &M);

    int count_options;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &qunstion[i].Mark, &count_options);
        qunstion[i].Ans = readanswer();
    }

    for (int i = 0; i < N; i++)
    {
        float score = 0;
        int answer;
        for (int j = 0; j < M; j++)
        {
            while (getchar() != '(')
                ;
            answer = readanswer();
            wrong_ans[j] = answer ^ qunstion[j].Ans; //异或 同假异真

            if (0 == wrong_ans[j])
            {
                score += qunstion[j].Mark;
            }
            else if ((wrong_ans[j] | qunstion[j].Ans) == qunstion[j].Ans)
            { //如果所得答案没有错选那么 | 上正确答案之后就可以得出正确答案
                score += 0.5 * qunstion[j].Mark;
            }

            for (int k = 0; k < MAX_OPTIONS; k++)
            {
                qunstion[j].WAnswer[k] += wrong_ans[j] >> k & 1;
                if (qunstion[j].WAnswer[k] > wrong_count_max)
                {
                    wrong_count_max = qunstion[j].WAnswer[k];
                }
            }

            while (getchar() != ')')
                ;
        }
        printf("%.1f\n", score);
    }

    if (wrong_count_max == 0)
    {
        printf("Too simple");
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < MAX_OPTIONS; j++)
            {
                if (qunstion[i].WAnswer[j] == wrong_count_max)
                {
                    printf("%d %d-%c\n", wrong_count_max, i + 1, j + 'a');
                }
            }
        }
    }
    return 0;
}

int readanswer()
{
    char c;
    int answer = 0, count;

    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        while ((c = getchar()) == ' ')
            ;
        answer |= 1 << (c - 'a');
    }
    return answer;
}