#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll m1[205] = {0};

ll dp[205][205] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m1[i];
        m1[i + n] = m1[i];
    }
    m1[2 * n + 1] = m1[1];
    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1; len + l - 1 <= 2 * n; l++) // 枚举所有长度为len的区间
        {
            int r = len + l - 1;
            for (int k = l; k < r; ++k) // 枚举这一堆最后一次合并的位置
            {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + m1[l] * m1[k + 1] * m1[r + 1]);
            }
        }
    }
    ll ans2 = 0;
    for (int l = 1, r = n; r < 2 * n; ++l, ++r)
    {
        ans2 = max(ans2, dp[l][r]);
    }
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