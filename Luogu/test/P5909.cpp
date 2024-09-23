#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int m, n;
struct edge
{
    int v;
    int w;
};

struct node
{
    int dis;
    int u;

    bool operator>(const node &a) const { return dis > a.dis; }
};

vector<edge> e[200005];
vector<ll> dis(100005, 1e12);
int vis[100005];
priority_queue<node, vector<node>, greater<node>> q;

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
        int w;
        cin >> u >> v >> w;
        tmp.w = w;
        tmp.v = v;
        e[u].push_back(tmp);
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