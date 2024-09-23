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
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, 0);
    map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (mp.count(a[i]))
        {
            dp[i] += mp[a[i]];
        }
        mp[a[i]] += i;
        ans += dp[i];
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