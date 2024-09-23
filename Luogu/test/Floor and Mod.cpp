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
    ll x;
    ll y;
    ll ans = 0;
    cin >> x >> y;
    for (int i = 1; i * i <= x; i++)
    {
        ll cnt = min(x / i - 1, y) - i;
        if (cnt > 0)
        {
            ans += cnt;
        }
    }
    cout << ans << endl;
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