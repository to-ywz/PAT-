#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char Name[1000][21] = {{'\0'}}, Line[21];
    int M, N, S, count = 0, r = 0, i;

    scanf("%d %d %d", &M, &N, &S);

    for (i = 0, S--; i < M; ++i)
    {
        scanf("%s", Line);
        if (i == S + count * N + r)
        {
            int flag = 1;
            for (int j = 0; j < count && flag; ++j)
            { //Cheack the repeat
                if (!strcmp(Name[j], Line))
                {
                    flag = 0;
                    r++;
                    break;
                }
            }
            if (flag)
            {
                strcpy(Name[count++], Line);
            }
        }
    }

    for (i = 0; i < count; ++i)
    {
        printf("%s\n", Name[i]);
    }
    if (0 == count)
    {
        printf("Keep going...");
    }

    return 0;
}
