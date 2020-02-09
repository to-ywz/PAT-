#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans[m], Mark[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", Mark + i);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", ans + i);
    }

    for (int i = 0; i < n; i++)
    {
        int score = 0, choice;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &choice);
            if (ans[j] == choice)
            {
                score += Mark[j];
            }
        }
        printf("%d\n", score);
    }

    return 0;
}