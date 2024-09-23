#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll v[105] = {0};
ll c[105] = {0};
ll dp1[10005] = {0};
ll dp2[10005] = {0};

void solve()
{
    ll n, t;
    cin >> n >> t;
    ll sum = 0;
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        sum += c[i] * v[i];
    }
    if (sum < t)
    {
        cout << -1 << endl;
        return;
    }
    memset(dp1, 0x3f, sizeof(dp1));
    memset(dp2, 0x3f, sizeof(dp2));
    dp1[0] = 0;
    dp2[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= mx; j++)
        {
            if (j >= v[i])
            {
                dp2[j] = min(dp2[j], dp2[j - v[i]] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c[i]; j <<= 1)
        {
            for (int k = t + mx; k >= j * v[i]; k--)
            {
                dp1[k] = min(dp1[k], dp1[k - j * v[i]] + j);
            }
            c[i] -= j;
        }
        if (c[i])
        {
            for (int k = t + mx; k >= c[i] * v[i]; k--)
            {
                dp1[k] = min(dp1[k], dp1[k - c[i] * v[i]] + c[i]);
            }
        }
    }

    // for (int i = 1; i <= t + mx; i++)
    // {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= mx; i++)
    // {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;

    ll mi = 0x3fffffff;
    for (int i = t; i <= t + mx; i++)
    {
        mi = min(mi, dp1[i] + dp2[i - t]);
    }
    if (mi == 0x3fffffff)
    {
        cout << -1 << endl;
        return;
    }
    cout << mi << endl;
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