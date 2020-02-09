#include <stdio.h>
#include <stdlib.h>

//退出条件
int cheak0(int arr[]);
//记录函数
void record(int arr[], char ch);
//输出函数
void print(int arr[]);

int main(void)
{
    char ch;
    int count[6] = {0};

    while ((ch = getchar()) != '\n')
    {
        record(count, ch);
    }

    while (cheak0(count))
    {
        print(count);
    }

    return 0;
}

int cheak0(int arr[])
{
    for (int i = 0; i < 6; i++)
    {
        if (arr[i])
        {
            return 1;
        }
    }
    return 0;
}

void record(int arr[], char ch)
{
    switch (ch)
    {
    case 'P':
        arr[0]++;
        break;
    case 'A':
        arr[1]++;
        break;
    case 'T':
        arr[2]++;
        break;
    case 'e':
        arr[3]++;
        break;
    case 's':
        arr[4]++;
        break;
    case 't':
        arr[5]++;
        break;
    }
}

void print(int arr[])
{
    for (int j = 0; j < 6; j++)
    {
        if (arr[j])
        {
            switch (j)
            {
            case 0:
                printf("P");
                arr[0]--;
                break;
            case 1:
                printf("A");
                arr[1]--;
                break;
            case 2:
                printf("T");
                arr[2]--;
                break;
            case 3:
                printf("e");
                arr[3]--;
                break;
            case 4:
                printf("s");
                arr[4]--;
                break;
            case 5:
                printf("t");
                arr[5]--;
                break;
            }
        }
    }
}