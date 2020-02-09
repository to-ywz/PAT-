/*#include <stdio.h>
#include <stdlib.h>

int compared(int a, int b, int c);

int main()
{
    int n;
    char TypeMap[] = {'J', 'C', 'B'};
    int Awin = 0, Bwin = 0, Nwin = 0;
    int BJ = 0, BC = 0, BB = 0, AJ = 0, AC = 0, AB = 0;
    char A, B;

    scanf("%d\n", &n);

    //开始统计各种次数
    while (n--)
    {
        scanf("%c %c", &A, &B);
        
        //偷懒求了B C J差值
        //A赢的情况8 ，-7， -1
        //B赢的情况-8， 7， 1
        switch (A - B)
        {
        case 0:                 //平局
            Nwin++; 
            break;
        case 8:                 //J - B 
            Awin++;
            AJ++;
            break;
        case -7:                //C - J
            Awin++;
            AC++;
            break;
        case -1:                //B - C
            Awin++;
            AB++;
            break;
        case -8:                //B - J, 从这里往下乙赢
            Bwin++;
            BJ++;
            break;
        case 7:                 //J - B
            Bwin++;
            BC++;
            break;
        case 1:                 //C - B
            Bwin++;
            BB++;
            break;
        }
        getchar();
    }

    int BigA = compared(AJ, AC, AB);        
    int BigB = compared(BJ, BC, BB);
    
    printf("%d %d %d\n", Awin, Nwin, Bwin);
    printf("%d %d %d\n", Bwin, Nwin, Awin);
    printf("%c %c\n", TypeMap[BigA], TypeMap[BigB]);
    return 0;
}

//三个数比大小
int compared(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (b > c)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
*/


#include <stdio.h> 
#include <stdlib.h>

//三目运算三个数比大小
#define cmp(a, b, c) a > b ? (a > c ?  0 : 2) : (b > c ? 1 : 2);

int main()
{
    int n;
    char TypeMap[] = {'J', 'C', 'B'};
    int Awin = 0, Bwin = 0, Nwin = 0;
    int BJ = 0, BC = 0, BB = 0, AJ = 0, AC = 0, AB = 0;
    char A, B;
    
    scanf("%d\n", &n);
    
    while (n--)
    {
        scanf("%c %c", &A, &B);
        
        switch (A-B)
        {
            case 0:Nwin++;break;
            case 8:Awin++;AJ++;break;
            case -7:Awin++;AC++;break;
            case -1:Awin++;AB++;break;
            case -8:Bwin++;BJ++;break;
            case 7:Bwin++;BC++;break;
            case 1:Bwin++;BB++;break;
        }
        getchar();//吞回车
    }

     int BigA = cmp(AJ, AC, AB);
     int BigB = cmp(BJ, BC, BB);

    printf("%d %d %d\n", Awin, Nwin, Bwin);
    printf("%d %d %d\n",Bwin, Nwin, Awin);
    printf("%c %c\n", TypeMap[BigA], TypeMap[BigB]);
    return 0;
}


 

