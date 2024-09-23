#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

void debug()
{
    return;
}

ll dp[100005] = {0};

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        dp[i] = ((y * (1 + dp[i - 1])) % mod * fast_pow(y - x, mod - 2, mod)) % mod;
    }
    cout << dp[n] << endl;
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