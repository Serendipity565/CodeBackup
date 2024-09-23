#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int m;
vector<int> g[100010];
int in[100010];
ll ans[100010];
map<pair<int, int>, ll> mp;

void debug()
{
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

void mysort()
{
    memset(ans, 0x80, sizeof(ans));
    queue<int> S;

    S.push(1);
    ans[1] = 0;
    ans[n] = -1;
    for (int i = 2; i <= n; i++)
    {
        if (!in[i])
        {
            S.push(i);
        }
    }
    while (!S.empty())
    {
        int u = S.front();
        S.pop();
        for (auto v : g[u])
        {
            ans[v] = max(ans[v], ans[u] + mp[{u, v}]);
            if (--in[v] == 0)
            {
                S.push(v);
            }
        }
    }
    cout << ans[n] << endl;
    return;
}

void solve()
{
    cin >> n >> m;
    int u, v;
    ll w;

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(v);
        in[v]++;
        if (mp.find({u, v}) != mp.end())
        {
            mp[{u, v}] = max(w, mp[{u, v}]);
        }
        else
        {
            mp[{u, v}] = w;
        }
    }
    mysort();
    // debug();
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
