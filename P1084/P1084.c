#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int d, n;
    int count = 0;
    char str1[100000] = {0}, str2[100000] = {0};
    char *s1 = str1, *s2 = str2, *temp;
    char *p1, *p2;

    scanf("%s %d", str1, &n);

    for (int i = 1; i < n; ++i)
    {
        for (p1 = s1, p2 = s2, count = 0; *p1; p1++)
        {
            count++;
            if (*p1 != *(p1 + 1))
            {
                *p2++ = *p1;
                *p2++ = count + '0';
                count = 0;
            }
        }
        temp = s1, s1 = s2, s2 = temp;
    }

    puts(s1);

    return 0;
}