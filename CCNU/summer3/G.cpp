#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<ll> mp[200005]; // 存树
vector<int> c(200005, 0);
vector<int> d(200005, 0);
ll ans[200005] = {0};
map<pair<ll, ll>, ll> wi;
ll f[200005] = {0};
ll mymax = 1;

void dfs(ll now)
{
    c[now] = 1;
    for (auto i : mp[now])
    {
        ll next = i;
        if (!c[next])
        {
            f[next] = f[now] + wi[{min(now, next), max(now, next)}];
            if (f[next] >= f[mymax])
            {
                mymax = next;
            }
            dfs(next);
            ans[now] = max(ans[now], ans[next] + wi[{min(now, next), max(now, next)}]);
        }
    }
    return;
}

void dfs2(ll now)
{
    d[now] = 1;
    for (auto i : mp[now])
    {
        ll next = i;
        if (!d[next])
        {
            dfs2(next);
            ans[now] = max(ans[now], ans[next] + wi[{min(now, next), max(now, next)}]);
        }
    }
    return;
}

void solve()
{
    ll n;
    cin >> n;
    ll u, v;
    ll w;
    ;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v >> w;
        mp[u].push_back(v);
        mp[v].push_back(u);
        wi[{min(u, v), max(u, v)}] = w;
    }

    ll head = 1;
    dfs(head);
    ll cnt = ans[head];
    memset(ans, 0, sizeof(ans));

    dfs2(mymax);
    cout << max(cnt, ans[mymax]) << endl;
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