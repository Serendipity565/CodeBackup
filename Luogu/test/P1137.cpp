#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int m;
vector<int> g[100005];
int in[100005];
int ans[100005];

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
            if (--in[v] == 0)
            {
                S.push(v);
                ans[v] = ans[u] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    // for (auto i : L)
    // {
    //     cout << i << endl;
    // }
    return;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
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