#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n;
    int count = 0, digit = 0, alpha = 0, other = 0;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        count = digit = alpha = other = 0;
        while ((ch = getchar()) != '\n')
        {
            count++;
            if (isdigit(ch))
            {
                digit++;
            }
            else if (isalpha(ch))
            {
                alpha++;
            }
            else if (ch != '.')
            {
                other++;
            }
        }

        if (count < 6)
        {
            printf("Your password is tai duan le.\n");
        }
        else if (other)
        {
            printf("Your password is tai luan le.\n");
        }
        else if (alpha && !digit)
        {
            printf("Your password needs shu zi.\n");
        }
        else if (!alpha && digit)
        {
            printf("Your password needs zi mu.\n");
        }
        else
        {
            printf("Your password is wan mei.\n");
        }
    }

    return 0;
}
