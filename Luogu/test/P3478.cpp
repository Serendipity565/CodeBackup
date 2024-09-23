#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll n;
ll dp[1000006] = {0};
vector<ll> ve[1000006];
bool c[1000006] = {false};
bool d[1000006] = {false};
ll s[1000006] = {0};
ll sum = 0;

void dfs1(ll u, ll ans)
{
    s[u] = 1;
    for (int i = 0; i < ve[u].size(); i++)
    {
        ll next = ve[u][i];
        if (!c[next])
        {
            c[next] = true;
            sum += ans;
            dfs1(next, ans + 1);
            s[u] += s[next];
        }
    }
    return;
}

void dfs2(int u)
{
    for (int i = 0; i < ve[u].size(); i++)
    {
        ll next = ve[u][i];
        if (!d[next])
        {
            dp[next] = dp[u] + n - 2 * s[next];
            d[next] = true;
            dfs2(next);
        }
    }
    return;
}

void solve()
{
    cin >> n;
    ll u, v;
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    c[1] = true;
    // cout << 0 << endl;
    dfs1(1, 1);
    dp[1] = sum;

    d[1] = true;
    dfs2(1);
    ll ans = 0;
    ll j = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            j = i;
        }
    }
    cout << j << endl;
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