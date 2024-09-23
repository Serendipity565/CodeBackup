#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll Q = 80112002;

int n;
int m;
vector<int> g[100005];
int in[100005];
ll ans[100005];
int out[100005];

void mysort()
{
    vector<int> L;
    queue<int> S;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            S.push(i);
            ans[i] = 1;
        }
    }
    while (!S.empty())
    {
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (auto v : g[u])
        {
            ans[v] += ans[u];
            ans[v] %= Q;
            if (--in[v] == 0)
            {
                S.push(v);
            }
        }
    }
    ll mymax = 0;
    for (int i = 1; i <= n; i++)
    {
        if (out[i] == 0)
        {
            mymax += ans[i];
            mymax %= Q;
        }
    }
    cout << mymax % Q << endl;
    return;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
        out[a]++;
    }
    mysort();
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