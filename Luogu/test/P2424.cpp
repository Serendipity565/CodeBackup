#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

ll sum(ll n)
{
    if (n <= 1)
    {
        return n;
    }
    ll ans = 0;
    ll r;
    for (ll l = 1; l <= n; l = r + 1) // 枚举约数
    {
        ll k = n / l; // 约数为l的有k个
        r = n / k;    // l到r中每个数的约数都有k个
        ans += k * (l + r) * (r - l + 1) / 2;
    }
    return ans;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    cout << sum(y) - sum(x - 1) << endl;
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