#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll w[105] = {0};
ll v[105] = {0};
ll dp[100005] = {0};

void solve()
{
    ll n, W;
    cin >> n >> W;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[i] = W + 10;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 1; j--)
        {
            if (j >= v[i])
            {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
            else
            {
                dp[j] = dp[j];
            }
        }
    }

    for (int i = sum; i >= 0; i--)
    {
        if (dp[i] <= W)
        {
            cout << i << endl;
            return;
        }
    }

    cout << 0 << endl;
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