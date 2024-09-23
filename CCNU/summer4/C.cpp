#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll a[100005] = {0};
vector<ll> dp(100005, 1);
vector<ll> c(100005, 1);
vector<ll> b[100005];
ll q = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll mymax = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    c[i] = c[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    c[i] += c[j];
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > mymax)
            {
                mymax = dp[i];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mymax == dp[i])
        {
            ans += c[i];
        }
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