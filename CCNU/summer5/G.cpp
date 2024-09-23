#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int f[100005] = {0};
int r[100005] = {0};

int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}

void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        if (r[fx] < r[fy])
        {
            f[fx] = fy;
        }
        else if (r[fx] > r[fy])
        {
            f[fy] = fx;
        }
        else
        {
            f[fy] = fx;
            r[fx]++;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        r[i] = 0;
    }
    int u, v;
    vector<vector<int>> ve(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
        merge(u, v);
    }
    set<int> ans;
    set<int> bad;
    for (int i = 1; i <= n; i++)
    {
        int fa = find(i);
        if (ve[i].size() == 3 && ans.find(fa) == ans.end())
        {
            ans.insert(fa);
        }
        else if (ve[i].size() >= 3)
        {
            bad.insert(fa);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int fa = find(a);
        int fb = find(b);
        int fc = find(c);
        if (fa == fb && fa == fc && ve[a].size() == 3 && bad.find(fa) == bad.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
