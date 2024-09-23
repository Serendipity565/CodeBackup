#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[200010] = {0};
ll dp[200010] = {0};

void solve()
{
    ll n;
    ll x;
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ll j = n;
    for (ll i = n; i >= 1; i--)
    {
        while (a[j] - a[i - 1] > x)
        {
            j--;
        }
        dp[i] = (j - i + 1) + dp[j + 2];
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        cnt += dp[i];
    }
    cout << cnt << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}