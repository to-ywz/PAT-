#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char ch, Password[21], user[21];

    scanf("%s %d", Password, &n);
    while (getchar() != '\n')
        ;
    while (n--)
    {
        scanf("%20[^\n]", user);
        ch = ungetc(getchar(), stdin);
        if (!strcmp(user, "#") && ch == '\n')
        {
            break;
        }
        else if (!strcmp(Password, user) && ch == '\n')
        {
            puts("Welcome in");
            break;
        }
        else
        {
            printf("Wrong password: %s", user);
            while (putchar(getchar()) != '\n')
                ;
            if (0 == n)
            {
                puts("Account locked");
            }
        }
    }

    return 0;
}