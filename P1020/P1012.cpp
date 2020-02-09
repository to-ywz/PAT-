#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int n;
    double D, sum = 0, d;
    cin >> n >> D;

    vector<double> cake(n), list;
    for (int i = 0; i < n; i++)
    {
        cin >> cake[i];
    }

    for (int i = 0; i < n; i++)
    {//填充cake[i]次单价
        cin >> d;
        for (int j = 0; j < cake[i]; j++)
        {
            list.push_back(d / cake[i]);
        }
    }

    sort(list.begin(), list.end(), greater<double>());

    for (int i = 0; i < D && i < list.size(); i++)
    {//一顿一顿往上加
        sum += list[i];
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;

    return 0;
}