#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll p[105] = {0};
ll c[105] = {0};
ll dp[55005] = {0};
const ll M = 100000000000;

void solve()
{
    ll h;
    ll n;
    cin >> n >> h;
    ll k = 5000 + h;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> c[i];
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i] = M;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = p[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
        }
    }
    for (int i = h; i <= k; i++)
    {
        if (dp[i] < dp[h])
        {
            dp[h] = dp[i];
        }
    }
    cout << dp[h] << endl;
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