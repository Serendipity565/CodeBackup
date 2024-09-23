#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[405][405] = {0};
int hi[55] = {0};
int ti[55] = {0};
int ki[55] = {0};

void solve()
{
    int h, t;
    cin >> h >> t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> hi[i] >> ti[i] >> ki[i];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = h; i >= 1; i--)
        {
            for (int j = t; j >= 1; j--)
            {
                if (i >= hi[k] && j >= ti[k])
                {
                    dp[i][j] = max(dp[i][j], dp[i - hi[k]][j - ti[k]] + ki[k]);
                }
            }
        }
    }
    cout << dp[h][t] << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tw;
    tw = 1;
    // cin >> t;
    while (tw--)
    {
        solve();
    }
    return 0;
}