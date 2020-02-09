#include <stdio.h>
#include <stdlib.h>

unsigned char color[128];

int main(void)
{
    char ch;
    int count = 0, lack = 0;

    while ((ch = getchar()) != '\n')
    {
        count++;
        color[ch]++;
    }

    while ((ch = getchar()) != '\n')
    {
        if (color[ch])
        {
            count--;
            color[ch]--;
            continue;
        }
        lack++;
    }

    if (lack)
    {
        printf("No %d\n", lack);
        return 0;
    }
    printf("Yes %d\n", count);

    return 0;
}
