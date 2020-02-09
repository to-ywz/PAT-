#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b);
void to_array(int a, char b[]);

int main()
{
    char num[5];
    int n;
    scanf("%d", &n);
    do
    {
        to_array(n, num);
        int max, min;

        sort(num, num + 4);
        sscanf(num, "%d", &min);
        sort(num, num + 4, cmp);
        sscanf(num, "%d", &max);
        
        printf("%04d - %04d = %04d\n", max, min, max - min);
        n = max - min;
    } while (n != 6174 && n != 0);

    return 0;
}

bool cmp(int a, int b)
{
    return a > b;
}

void to_array(int a, char b[])
{
    for (int i = 0; i < 4; i++)
    {
        b[i] = a % 10 + '0';
        a /= 10;
    }
}