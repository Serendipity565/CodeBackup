#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'M')
        {
            a = i;
            // cout << a;
        }
        if (s[i] == 'R')
        {
            b = i;
            // cout << b;
        }
    }
    if (b < a)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}