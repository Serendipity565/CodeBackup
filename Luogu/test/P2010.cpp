#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

bool is(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

bool check(int year, int month, int day)
{
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is(year) && month == 2)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int data1;
    int data2;
    cin >> data1;
    cin >> data2;
    int year1 = data1 / 10000;
    int month1 = data1 % 10000 / 100;
    int day1 = data1 % 100;
    int year2 = data2 / 10000;
    int month2 = data2 % 10000 / 100;
    int day2 = data2 % 100;
    ll sum = 0;
    for (int i = year1; i <= year2; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            for (int k = 1; k <= 31; k++)
            {
                string s1 = to_string(i * 10000 + j * 100 + k);
                string s2 = to_string(i * 10000 + j * 100 + k);
                reverse(s1.begin(), s1.end());
                if (s1 == s2 && check(i, j, k) && (i * 10000 + j * 100 + k) >= data1 && (i * 10000 + j * 100 + k) <= data2)
                {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}