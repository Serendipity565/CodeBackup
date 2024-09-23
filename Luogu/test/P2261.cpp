#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

ll sum(ll n, ll k)
{
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        if (k / l != 0)
        {
            r = min(k / (k / l), n);
        }
        else
        {
            r = n;
        }
        ans += (k / l) * (r - l + 1) * (l + r) / 2;
    }
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = n * k - sum(n, k);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}