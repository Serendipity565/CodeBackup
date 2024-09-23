#include <bits/stdc++.h>
using namespace std;
map<char, int> m;

bool check(int k)
{
    if (k <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    int mymax = 0;
    int mymin = s.size();
    for (auto x : m)
    {
        if (x.second > mymax)
        {
            mymax = x.second;
        }
        if (x.second < mymin)
        {
            mymin = x.second;
        }
    }
    if (check(mymax - mymin))
    {
        cout << "Lucky Word" << "\n"
             << mymax - mymin;
    }
    else
    {
        cout << "No Answer" << "\n"
             << 0;
    }
    return 0;
}