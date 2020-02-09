
#include <stdio.h>

struct node
{
    int add, data, next;
} a[100010], b[100010], c[100010]; //a按地址下标存放输入数据，b依次存放顺序链表，c

int main()
{
    int beginadd = 0, n = 0, k = 0;
    int i = 0, j = 0, index = 0;
    scanf("%d%d%d", &beginadd, &n, &k);
    //按地址下标存放输入数据
    for (i = 0; i < n; i++)
    {
        scanf("%d", &index);
        scanf("%d %d", &a[index].data, &a[index].next);
    }
    //依次存放顺序链表
    int num = 0;
    for (i = beginadd; i != -1; i = a[i].next)
    {
        b[num].add = i;
        b[num].data = a[i].data;
        b[num].next = a[i].next;
        num++;
    }
    int s = num / k, y = num % k; //s为反转块数量，y为不反转链表节点数量
                                  //按需反转，无需考虑next地址，因为顺序正确，next地址就是下一个节点的add
    int pos = 0;
    for (i = 1; i <= s; i++)
    {
        for (j = i * k - 1; j >= (i - 1) * k; j--)
        {
            c[pos].add = b[j].add;
            c[pos].data = b[j].data;
            pos++;
        }
    }
    if (y != 0)
    {
        for (i = s * k; i < num; i++)
        {
            c[pos].add = b[i].add;
            c[pos].data = b[i].data;
            pos++;
        }
    }

    for (int k = 0; k < pos - 1; k++)
    {
        printf("%05d %d %05d\n", c[k].add, c[k].data, c[k + 1].add);
    }
    printf("%05d %d -1\n", c[pos - 1].add, c[pos - 1].data);
    return 0;
}
