#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int cst[505][505] = {0};
int dp[505][505] = {0};
int tim[505] = {0};
int cnt[505] = {0};

void solve()
{
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    memset(cst, 0x3f, sizeof(cst));
    char temp;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> temp;
            if (temp == '1')
            {
                cnt[i]++;
                tim[cnt[i]] = j;
            }
        }
        cst[i][cnt[i]] = 0;
        for (int len = 1; len <= cnt[i]; ++len)
        {
            for (int l = 1; l + len - 1 <= cnt[i]; ++l)
            {
                int r = l + len - 1;
                cst[i][cnt[i] - len] = min(cst[i][cnt[i] - len], tim[r] - tim[l] + 1);
            }
        }
        sum += cst[i][0];
    }
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 0; j <= 4; j++)
    //     {
    //         cout << cst[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int q = 0; q <= min(j, cnt[i]); q++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - q] + cst[i][q]);
            }
        }
    }
    // for (int j = 0; j <= k; j++)
    // {
    //     cout << dp[n][j] << " ";
    // }
    if (k == 0)
    {
        cout << sum << endl;
        return;
    }
    cout << dp[n][k] << endl;
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