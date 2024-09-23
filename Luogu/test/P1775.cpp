#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int m[305] = {0};
int dp[305][305];

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        m[i] += m[i - 1];
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1; len + l - 1 <= n; l++) // 枚举所有长度为len的区间
        {
            int r = len + l - 1;
            for (int k = l; k < r; ++k) // 枚举这一堆最后一次合并的位置
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + m[r] - m[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
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