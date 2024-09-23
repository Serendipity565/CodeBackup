#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int n, a[16005], f[16005], ans = -2147483647;
vector<int> ve[16005];

void dfs(int u, int fa)
{
    f[u] = a[u];
    for (int i = 0; i < ve[u].size(); i++)
    {
        int t = ve[u][i];
        if (t != fa)
        {
            dfs(t, u);
            if (f[t] > 0)
            {
                f[u] += f[t];
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i]);
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
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}