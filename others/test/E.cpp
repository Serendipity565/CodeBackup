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
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    for (auto x : s)
    {
        if (x == '(')
        {
            l++;
        }
        else if (x == ')')
        {
            r++;
        }
        if (l < r)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (l != r)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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