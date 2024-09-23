#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int m, n, s;
struct edge
{
    int v;
    ll w;
};

struct node
{
    ll dis;
    int u;

    bool operator>(const node &a) const { return dis > a.dis; }
};

vector<edge> e[200005];
vector<ll> dis(100005, 1e12);
int vis[100005];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int s)
{
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v;
            ll w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m >> s;
    edge tmp;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        tmp.w = w;
        tmp.v = v;
        e[u].push_back(tmp);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
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