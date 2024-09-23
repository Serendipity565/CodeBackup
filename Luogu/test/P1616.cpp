#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll w[10004] = {0};
ll v[10004] = {0};
ll dp[10000007] = {0};

void solve()
{
    ll t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = w[i]; j <= t; j++)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[t] << endl;
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