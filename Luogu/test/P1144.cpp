#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll Q = 100003;
int m, n;
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

vector<edge> e[2000006];
vector<ll> dis(1000006, 1e12);
int vis[1000006];
vector<ll> ans(1000006, 1);
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int s)
{
    dis[s] = 0;
    q.push({0, s});
    ans[1] = 1;
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
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                ans[v] = ans[u];
                q.push({dis[v], v});
            }
            else if (dis[v] == dis[u] + 1)
            {
                ans[v] += ans[u];
                ans[v] %= Q;
                // q.push({dis[v], v});
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
    cin >> n >> m;
    edge tmp;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        tmp.w = 1;
        tmp.v = v;
        e[u].push_back(tmp);
        tmp.v = u;
        e[v].push_back(tmp);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 1e12)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans[i] % Q << endl;
        }
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