#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll n, s;
struct edge
{
    ll v;
    ll w;
};

struct node
{
    ll dis;
    ll u;

    bool operator>(const node &a) const { return dis > a.dis; }
};

vector<edge> e[400005];
vector<ll> dis(400005, 1e18);
ll vis[400005];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(ll s)
{
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        ll u = q.top().u;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto ed : e[u])
        {
            ll v = ed.v;
            ll w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (ll i = 1; i < n; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        e[i].push_back({i + 1, a});
        e[i].push_back({c, b});
    }

    dijkstra(1);
    cout << dis[n] << endl;
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
