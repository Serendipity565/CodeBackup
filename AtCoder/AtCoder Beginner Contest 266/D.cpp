#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll dp[100005][5] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    int t;
    int pre = 0;
    int x;
    ll a;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> x >> a;
        int dif = t - pre;
        for (int j = 0; j <= min(t, 4); j++)
        {
            int mymin = max(0, j - dif);
            int mymax = min(4, j + dif);
            for (int k = mymin; k <= mymax; k++)
            {
                dp[t][j] = max(dp[pre][k], dp[t][j]);
            }
            if (j == x)
            {
                dp[t][j] += a;
            }
        }
        pre = t;
    }
    ll ans = 0;
    for (int j = 0; j <= min(t, 4); j++)
    {
        ans = max(ans, dp[t][j]);
    }
    cout << ans << endl;
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