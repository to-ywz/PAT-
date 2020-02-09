#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//比较喜欢宏定义，这样写代码移植性强
#define EARLIESTYEAR    1814
#define NOWYEAR         2014
#define NOWMONTH        9
#define NOWDAY          6

typedef struct
{
    char name[6];
    int year, month, day;
} PersonalData;

//输入出生日期合法判断
static int Islegal(PersonalData *temp);
//查找最大最小年龄的人
static void Find(PersonalData *MAX, PersonalData *MIN, const PersonalData *temp);

int main(void)
{
    int n, count = 0;
    PersonalData theoldest = {"\0", 2015, 12, 31}, theyoungest = {"\0", 1813, 1, 1};
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        PersonalData temp;
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);

        if (Islegal(&temp))
        {
            continue;
        }
        Find(&theoldest, &theyoungest, &temp);
        count++;
    }
    
    //这里可以直接加个if特判count == 0的情况，我脑子有坑才这么写
    printf("%d%s%s%s%s", count, 0 == count ? "" : " ", 0 == count ? "" : theoldest.name, 0 == count ? "" : " ", 0 == count ? "" : theyoungest.name);

    return 0;
}

static void Find(PersonalData *MAX, PersonalData *MIN, const PersonalData *temp)
{
    //分了三种情况，出生年月日小于于最大值的年月日的就交换
    //生的越早，年份越小，年纪越老
    if ((MAX->year > temp->year) ||
        (MAX->year == temp->year && MAX->month > temp->month) ||
        (MAX->year == temp->year && MAX->month == temp->month && MAX->day > temp->day))
    {
        *MAX = *temp;
    }
    //同理
    if ((MIN->year < temp->year) ||
        (MIN->year == temp->year && MIN->month < temp->month) ||
        (MIN->year == temp->year && MIN->month == temp->month && MIN->day < temp->day))
    {
        *MIN = *temp;
    }
}

static int Islegal(PersonalData *temp)
{
    //年超出的
    if (temp->year > NOWYEAR || temp->year < EARLIESTYEAR)
    {
        return 1;
    }
    //月份超出的
    if ((NOWYEAR == temp->year && temp->month > NOWMONTH) ||
        (EARLIESTYEAR == temp->year && temp->month < NOWMONTH))
    {
        return 1;
    }
    //日期超出的
    if ((NOWYEAR == temp->year && NOWMONTH == temp->month && temp->day > NOWDAY) ||
        (EARLIESTYEAR == temp->year && NOWMONTH == temp->month && temp->day < NOWDAY))
    {
        return 1;
    }

    return 0;
}