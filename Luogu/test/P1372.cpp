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
    ll n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (k >= n)
        {
            cout << 1 << endl;
            return;
        }
        if (n / i >= k)
        {
            continue;
        }
        else
        {
            cout << i - 1 << endl;
            return;
        }
    }
    cout << n << endl;
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