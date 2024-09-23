#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int w[105][105] = {0};
int dp[20005] = {0};

void solve()
{
    int s, n, m;
    cin >> s >> n >> m;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[j][i];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(w[i] + 1, w[i] + 1 + s);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            for (int k = 0; k <= s; k++)
            {
                if (j >= w[i][k] * 2 + 1)
                {
                    dp[j] = max(dp[j], dp[j - w[i][k] * 2 - 1] + k * i);
                }
                else
                {
                    dp[j] = dp[j];
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[m] << endl;
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