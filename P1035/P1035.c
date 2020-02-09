#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Merge = 0;
void InsertSorted(int arr[], int mid[], int n);
void MergeSorted(int arr[], int mid[], int n);
int ArrayEqual(int arr[], int ary[], int n);
void ArrayPrint(int arr[], int n);

int main(void)
{
    static int n;
    int arr[101];
    int ary[101];
    int mid[101];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        ary[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mid[i]);
    }

    InsertSorted(arr, mid, n);
    if (Merge)
    {
        MergeSorted(ary, mid, n);
    }

    return 0;
}

//插入排序
void InsertSorted(int arr[], int mid[], int n)
{
    int j, temp;

    for (int i = 1; i < n; i++)
    {
        j = i;
        temp = arr[i];
        while (j > 0 && temp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;

        if (ArrayEqual(arr, mid, n))
        {
            j = ++i;
            temp = arr[i];
            while (j > 0 && temp < arr[j - 1])
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = temp;
            printf("Insertion Sort\n");
            ArrayPrint(arr, n);
            Merge = 0;
            return;
        }
    }
    Merge = 1;
}

void MergeAdd(int arr[], int left, int mid, int right, int *tmp)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= right)
    {
        tmp[k++] = arr[j++];
    }
    //把tmp中的内容拷给arr数组中
    //进行归并的时候，处理的区间是arr[left,right),对应的会把
    //这部分区间的数组填到tmp[left,right)区间上
    memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int arr[], int len, int *tmp, int mid[], int n)
{
    if (len <= 1)
    {
        return;
    }
    int flag = 0;

    //定义一个步长gap，初始值为1，相当于每次只合并两个长度为1的元素
    for (int gap = 1; gap <= len; gap *= 2)
    {
        for (int i = 0; i <= len; i += 2 * gap)
        {
            int beg = i;
            int mid = (gap - 1) + i;
            if (mid >= len)
            {
                mid = len;
            }
            int end = mid + gap;
            if (end >= len)
            {
                end = len;
            }
            MergeAdd(arr, beg, mid, end, tmp);
        }
        if (flag)
        {
            printf("Merge Sort\n");
            ArrayPrint(arr, n);
            return;
        }
        if (ArrayEqual(arr, mid, n))
        {
            flag = 1;
        }
    }
}
//归并排序接口
void MergeSorted(int arr[], int mid[], int n)
{
    int *temp = malloc(sizeof(int) * n);
    MergeSort(arr, n - 1, temp, mid, n);
    free(temp);
}
//输出数组
void ArrayPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], n - 1 == i ? "" : " ");
    }
}
//判断相等
int ArrayEqual(int arr[], int ary[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != ary[i])
        {
            return 0;
        }
    }
    return 1;
}