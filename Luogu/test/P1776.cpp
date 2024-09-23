#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[1000005];
int w[1000005], v[1000005];

void solve()
{
    int a, b, c;
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        for (int j = 1; j <= c; j <<= 1)
        {
            cnt++;
            v[cnt] = j * a, w[cnt] = j * b;
            c -= j;
        }
        if (c)
        {
            cnt++;
            v[cnt] = a * c, w[cnt] = b * c;
        }
    }

    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = m; j >= w[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
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