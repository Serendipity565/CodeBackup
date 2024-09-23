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
    string s;
    cin >> s;
    int len = sqrt(n);
    if (len * len != n)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < len || (i >= n - len))
        {
            if (s[i] == '1')
            {
                continue;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (i % len == 0 || ((i % len) == (len - 1)))
        {
            if (s[i] == '1')
            {
                continue;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                continue;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}