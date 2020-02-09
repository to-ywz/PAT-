#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalind(char num[]);
void Add(char A[], char B[]);
void Reverse(char A[], char B[]);

int main(void)
{
    int i = 0;
    char numA[1100] = "\0", numB[1100] = "\0";

    scanf("%s", numA);

    while (i < 10 && 0 == isPalind(numA))
    {
        Reverse(numA, numB);
        printf("%s + %s = ", numA, numB);
        Add(numA, numB);
        printf("%s\n", numA);
        i++;
    }

    if (10 == i)
    {
        printf("Not found in 10 iterations.");
    }
    else
    {
        printf("%s is a palindromic number.", numA);
    }

    return 0;
}

int isPalind(char num[])
{
    int len = strlen(num);
    for (size_t i = 0; i < len / 2; i++)
    {
        if (num[i] != num[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

void Add(char A[], char B[])
{
    int lenA = strlen(A);
    int sum, carry = 0;
    for (int i = lenA - 1; i >= 0; i--)
    {
        sum = (A[i] - '0') + (B[i] - '0') + carry;
        A[i] = sum % 10 + '0';
        carry = (sum / 10);
    }
    //最高位存在进位
    if (carry)
    {
        memmove(A + 1, A, lenA + 1);
        A[0] = carry + '0';
    }
}

void Reverse(char A[], char B[])
{
    int len = strlen(A);
    for (int i = 0; i < len; i++)
    {
        B[len - i - 1] = A[i];
    }
}