#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

int a[200005] = {0};
ll dp[200005][2] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1][1] = a[1];
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][1] + 2 * a[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
    }
    cout << max(dp[n][1], dp[n][0]);
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