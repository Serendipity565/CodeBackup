#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int m, n;
struct edge
{
    int v;
    ll w;
};
vector<edge> e[2505];
ll dis[2505] = {0};
int vis[2505] = {0};
int cnt[2505] = {0};
queue<int> q;

bool spfa(int s)
{
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                {
                    return false;
                }
                if (!vis[v])
                {
                    q.push(v), vis[v] = 1;
                }
            }
        }
    }
    return true;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m;
    edge tmp;
    ll mymin = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        mymin = min(w, mymin);
        tmp.w = w;
        tmp.v = v;
        e[u].push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = mymin;
    }
    spfa(1);
    if (dis[n] == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }

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