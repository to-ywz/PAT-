#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long GCD(long x, long y) { return (0 == y) ? x : GCD(y, x % y); }
void Simplify(long Molecule, long Denominator);

int main(void)
{

    long DivdMoce, DivdDenom, DivsMoce, DivsDenom;

    scanf("%ld/%ld %ld/%ld", &DivdMoce, &DivdDenom, &DivsMoce, &DivsDenom);

    Simplify(DivdMoce, DivdDenom); printf(" + "); Simplify(DivsMoce, DivsDenom); printf(" = "); Simplify(DivdMoce * DivsDenom + DivdDenom * DivsMoce, DivdDenom * DivsDenom); printf("\n");
    Simplify(DivdMoce, DivdDenom); printf(" - "); Simplify(DivsMoce, DivsDenom); printf(" = "); Simplify(DivdMoce * DivsDenom - DivdDenom * DivsMoce, DivdDenom * DivsDenom); printf("\n");
    Simplify(DivdMoce, DivdDenom); printf(" * "); Simplify(DivsMoce, DivsDenom); printf(" = "); Simplify(DivdMoce * DivsMoce, DivdDenom * DivsDenom); printf("\n");
    Simplify(DivdMoce, DivdDenom); printf(" / "); Simplify(DivsMoce, DivsDenom); printf(" = "); Simplify(DivdMoce * DivsDenom, DivdDenom * DivsMoce);

    return 0;
}

void Simplify(long Molecule, long Denominator)
{
    //分母是否合法
    if (0 == Molecule * Denominator)
    {
        printf("%s", 0 == Denominator ? "Inf" : "0");
        return;
    }

    //正负号判定
    int flag = ((Molecule > 0 && Denominator < 0) || (Molecule < 0 && Denominator > 0));
    //先输出符号
    printf("%s", 0 == flag ? "" : "(-");

    //去除符号问题，简化最大公约数求取过程
    Molecule = abs(Molecule);
    Denominator = abs(Denominator);

    //获取商，准备输出带分数整数部分
    long Interger = Molecule / Denominator;
    //如果是假分数，那么化为带分数并输出整数部分
    if (0 != Interger)
    {
        printf("%ld", Interger);
    }
    //检测能否被整除
    if (0 == Molecule % Denominator)
    {
        if (1 == flag)
        {
            printf(")");
        }
        return;
    }
    //补上带分数正整数部分的空格
    if (0 != Interger)
    {
        printf(" ");
    }

    Molecule = Molecule - Denominator * Interger;
    long gcd = GCD(Molecule, Denominator);

    printf("%ld/%ld%s", Molecule / gcd, Denominator / gcd, 1 == flag ? ")" : "");
}

/**
 * /