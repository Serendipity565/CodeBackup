#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int d[10004] = {0};
vector<int> ve[10004];
map<pair<int, int>, int> w;
int n, m, s, t;

bool check(int mid)
{
    memset(d, 0, sizeof(d));
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : ve[x])
        {
            int y = i;
            if (w[{min(x, y), max(x, y)}] <= mid)
            {
                if (d[y] == 0)
                {
                    if (y == t)
                    {
                        return true;
                    }
                    d[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    return false;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m >> s >> t;
    int u, v, wi;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> wi;
        ve[u].push_back(v);
        ve[v].push_back(u);
        if (w.find({min(u, v), max(u, v)}) != w.end())
        {
            w[{min(u, v), max(u, v)}] = min(wi, w[{min(u, v), max(u, v)}]);
        }
        else
        {
            w[{min(u, v), max(u, v)}] = wi;
        }
    }

    int l = 0;
    int r = 10000;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
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