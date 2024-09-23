#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int m[105] = {0};
int s[205] = {0};
int dp[205][205];
int dp2[205][205] = {0};

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        s[i] = m[i] + s[i - 1];
        dp[i][i] = 0;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        s[i] = s[i - 1] + m[i - n];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1; len + l - 1 <= 2 * n; l++) // 枚举所有长度为len的区间
        {
            int r = len + l - 1;
            for (int k = l; k < r; ++k) // 枚举这一堆最后一次合并的位置
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
                dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    int ans1 = 1e9;
    int ans2 = 0;
    for (int l = 1, r = n; r < 2 * n; ++l, ++r)
    {
        ans1 = min(ans1, dp[l][r]);
        ans2 = max(ans2, dp2[l][r]);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
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