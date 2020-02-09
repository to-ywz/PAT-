#include <stdio.h>
#include <stdlib.h>

int TeamMark[1001];

int main(void)
{
    int n, TeamID, mark;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d-%*[^ ]%d", &TeamID, &mark);//%*[^ ]过滤空格之前的所有字符
        TeamMark[TeamID] += mark;
    }

    int max = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (TeamMark[i] > TeamMark[max])
        {
            max = i;
        }
    }

    printf("%d %d\n", max, TeamMark[max]);
    return 0;
}