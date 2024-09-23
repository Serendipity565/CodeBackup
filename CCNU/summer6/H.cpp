#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    ll p = 1;
    ll ans = 0;
    for (ll i = 1;; i++)
    {
        p = p / __gcd(p, i) * i;
        if (p > n)
        {
            break;
        }
        ans += n / p;
        ans %= mod;
    }
    ans = (ans + n) % mod;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}