#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int n, m;
vector<int> G[100005];
int in[100005];
double f[100005] = {0};
int out[100005] = {0};
map<pair<int, int>, int> mp;

void mysort()
{
    queue<int> S;
    S.push(n);

    while (!S.empty())
    {
        int u = S.front();
        S.pop();
        for (auto v : G[u])
        {
            f[v] += (f[u] + mp[{u, v}]) / out[v];
            if (--in[v] == 0)
            {
                S.push(v);
            }
        }
    }
}

void solve()
{

    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        mp[{v, u}] = w;
        in[u]++;
        out[u]++;
        G[v].push_back(u);
    }
    mysort();
    cout << fixed << setprecision(2) << f[1] << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << endl;
    // }
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