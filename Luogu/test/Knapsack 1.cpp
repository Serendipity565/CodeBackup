#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll w[105] = {0};
ll v[105] = {0};
ll dp[105][100005] = {0};

void solve()
{
    ll n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    /*
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][W] << endl;
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