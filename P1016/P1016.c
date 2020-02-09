#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

int main(void)
{
    int Num1 = 0, Num2 = 0;
    char Numchar1, Numchar2;
    char Numstr1[MAXSIZE], Numstr2[MAXSIZE];

    scanf("%s %c %s %c", Numstr1, &Numchar1, Numstr2, &Numchar2);
    //printf("%s%c%s%d", Numstr1, Numchar1, Numstr2, Numchar2);

    for (int i = 0; '\0' != Numstr1[i] || '\0' != Numstr2[i]; i++)
    {
        if (Numstr1[i] == Numchar1)
        {
            Num1 *= 10;
            Num1 += Numchar1 - '0';
        }
        if (Numstr2[i] == Numchar2)
        {
            Num2 *= 10;
            Num2 += Numchar2 - '0';
        }
    }

    printf("%d", Num1 + Num2);
}