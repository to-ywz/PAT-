#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    double b;
    char buf[512] = "";

    //输出字符串
    sscanf("123456 ", "%s", buf);
    printf("%s\n", buf);

    //输出浮点
    sscanf(buf, "%lf", &b);
    printf("%lf\n", b);

    //输出整型
    sscanf(buf, "%d", &a);
    printf("%d\n", a);

    //特殊输出于scanf类比
    sscanf("123456 ", "%4s", buf);
    printf("%s\n", buf);

    sscanf("123456 abcdedf", "%[^ ]", buf);
    printf("%s\n", buf);

    sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
    printf("%s\n", buf);

    sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
    printf("%s\n", buf);

    sscanf("hello, world", "%*s%s", buf); //%*s表示第一个匹配到的%s被过滤掉
    printf("%s\n", buf);

    
    return 0;
}