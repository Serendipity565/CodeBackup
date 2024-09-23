#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{

    return;
}

void solve()
{
    string s;
    cin >> s;
    ll a = 0;
    ll b = 0;
    int i = 0;
    while (i < s.size())
    {
        a = a * 10 + (s[i] - '0');
        i++;
        if (i < s.size())
        {
            b = b * 10 + (s[i] - '0') % 10;
            i++;
        }
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
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