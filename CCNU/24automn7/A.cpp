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
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
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