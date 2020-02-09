#include <iostream>
#include <vector>
#include <iomanip>

int main(void)
{
    using std::cout;
    bool isRemainder1 = false;
    int TestNumber, sign = 1, isRemainder3 = 0;
    std::cin >> TestNumber;
    std::vector<int> Remainder(5, -1);

    while (TestNumber--)
    {
        int temp;
        std::cin >> temp;

        switch (temp % 5)
        {
        case 0:
            if (0 == temp % 2)
            {
                Remainder[0] += temp;
            }
            break;
        case 1:
            isRemainder1 = true;
            if (1 == sign)
            {
                Remainder[1] += temp;
            }
            else
            {
                Remainder[1] -= temp;
            }
            sign = !sign;
            break;
        case 2:
            Remainder[2]++;
            break;
        case 3:
            Remainder[3] += temp;
            isRemainder3++;
            // /cout << temp << " " << isRemainder3 << " " << Remainder[3] << std::endl;
            break;
        case 4:
            if (Remainder[4] < temp)
            {
                Remainder[4] = temp;
            }
            break;
        }
    }

    for (int i = 0; i < Remainder.size() - 1; i++)
    {
        if (-1 == Remainder[i])
        {
            if (true == isRemainder1 && 1 == i)
            {
                Remainder[i]++;
            }
            continue;
        }
        Remainder[i]++;
    }

    for (int i = 0; i < Remainder.size(); i++)
    {
        if (-1 == Remainder[i])
        {
            cout << "N";
        }
        else
        {
            if (3 == i)
            {
                cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << (Remainder[3] * 0.1) / (isRemainder3 * 0.1);
            }
            else
            {
                cout << Remainder[i];
            }
        }

        if (i != Remainder.size() - 1)
        {
            cout << " ";
            continue;
        }
        cout << std::endl;
    }

    return 0;
}