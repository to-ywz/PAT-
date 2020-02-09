#include <stdio.h>
#include <stdlib.h>

#define SQR(X)              ((X) * (X))
#define R(COLOR)            ((COLOR & 0XFF0000) >> 16)
#define G(COLOR)            ((COLOR & 0x00FF00) >> 8)
#define B(COLOR)            ((COLOR & 0x0000FF))
#define DISTANCE(C1, C2)    (SQR(R(C1) - R(C2)) + SQR(G(C1) - G(C2)) + SQR(B(C1) - B(C2))) //空间内两点距离

int maxtrix[1000][1000];
int isUnique(int x, int y, int x0, int y0);

int main(void)
{
    int M, N, TOL;
    scanf("%d %d %d", &M, &N, &TOL);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &maxtrix[i][j]);
        }
    }

    int count = 0, M0, N0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {//模拟
            if ((i > 0 && j > 0 ? DISTANCE(maxtrix[i][j], maxtrix[i - 1][j - 1]) > SQR(TOL) : 1)
            &&  (i > 0          ? DISTANCE(maxtrix[i][j], maxtrix[i - 1][j    ]) > SQR(TOL) : 1)
            &&  (i > 0 && j < M ? DISTANCE(maxtrix[i][j], maxtrix[i - 1][j + 1]) > SQR(TOL) : 1)
            &&  (         j > 0 ? DISTANCE(maxtrix[i][j], maxtrix[i    ][j - 1]) > SQR(TOL) : 1)
            &&  (         j < M ? DISTANCE(maxtrix[i][j], maxtrix[i    ][j + 1]) > SQR(TOL) : 1)
            &&  (i < N && j > 0 ? DISTANCE(maxtrix[i][j], maxtrix[i + 1][j - 1]) > SQR(TOL) : 1)
            &&  (i < N          ? DISTANCE(maxtrix[i][j], maxtrix[i + 1][j    ]) > SQR(TOL) : 1)
            &&  (i < N && j < M ? DISTANCE(maxtrix[i][j], maxtrix[i + 1][j + 1]) > SQR(TOL) : 1)
            && isUnique(N, M, i, j)/*验重函数*/)
            {
                count++;
                N0 = i;
                M0 = j;
            }
        }
    }

    if (count == 0)
    {
        printf("Not Exist");
    }
    if (count == 1)
    {
        printf("(%d, %d): %d", M0 + 1, N0 + 1, maxtrix[N0][M0]);
    }
    if (count >= 2)
    {
        printf("Not Unique");
    }

    return 0;
}

int isUnique(int x, int y, int x0, int y0)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (maxtrix[i][j] == maxtrix[x0][y0] && !(i == x0 && j == y0)/*行列并且值不相等*/)
            {
                return 0;
            }
        }
    }
    return 1;
}