#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    int pow;
    bool flag = true;
    for (int i = n; i >= 1; i--)
    {
        cin >> pow;
        if (pow == 0)
        {
            continue;
        }
        else if (flag)
        {
            if (i == 1)
            {
                if (pow == 1 || pow == -1)
                {
                    if (pow > 0)
                    {
                        cout << "x";
                    }
                    else
                    {
                        cout << "-" << "x";
                    }
                }
                else
                {
                    if (pow > 0)
                    {
                        cout << pow << "x";
                    }
                    else
                    {
                        cout << pow << "x";
                    }
                }
                flag = false;
                break;
            }
            if (pow == 1 || pow == -1)
            {
                if (pow > 0)
                {
                    cout << "x^" << i;
                }
                else
                {
                    cout << "-" << "x^" << i;
                }
            }
            else
            {
                if (pow > 0)
                {
                    cout << pow << "x^" << i;
                }
                else
                {
                    cout << pow << "x^" << i;
                }
            }
            flag = false;
        }
        else
        {
            if (i == 1)
            {
                if (pow == 1 || pow == -1)
                {
                    if (pow > 0)
                    {
                        cout << "+" << "x";
                    }
                    else
                    {
                        cout << "-" << "x";
                    }
                }
                else
                {
                    if (pow > 0)
                    {
                        cout << "+" << pow << "x";
                    }
                    else
                    {
                        cout << pow << "x";
                    }
                }
                break;
            }
            if (pow == 1 || pow == -1)
            {
                if (pow > 0)
                {
                    cout << "+" << "x^" << i;
                }
                else
                {
                    cout << "-" << "x^" << i;
                }
            }
            else
            {
                if (pow > 0)
                {
                    cout << "+" << pow << "x^" << i;
                }
                else
                {
                    cout << pow << "x^" << i;
                }
            }
        }
    }
    cin >> pow;

    if (flag)
    {
        cout << pow;
    }
    else
    {
        if (pow != 0)
        {
            if (pow > 0)
            {
                cout << "+" << pow;
            }
            else
            {
                cout << pow;
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}