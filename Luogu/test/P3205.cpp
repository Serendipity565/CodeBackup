#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int dp[2010][2010][2] = {0};
int a[2010] = {0};
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][i][0] = 1;
    }
    for (int len = 1; len <= n; len++)
        for (int i = 1, j = i + len; j <= n; i++, j++)
        {
            if (a[i] < a[i + 1])
            {
                dp[i][j][0] += dp[i + 1][j][0];
            }
            if (a[i] < a[j])
            {
                dp[i][j][0] += dp[i + 1][j][1];
            }
            if (a[j] > a[i])
            {
                dp[i][j][1] += dp[i][j - 1][0];
            }
            if (a[j] > a[j - 1])
            {
                dp[i][j][1] += dp[i][j - 1][1];
            }
            dp[i][j][0] %= 19650827;
            dp[i][j][1] %= 19650827;
        }
    cout << (dp[1][n][0] + dp[1][n][1]) % 19650827;
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