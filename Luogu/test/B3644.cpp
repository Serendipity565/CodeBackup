#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int m;
vector<int> G[105];
int in[105];

bool mysort()
{
    vector<int> L;
    queue<int> S;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            S.push(i);
        }
    }
    while (!S.empty())
    {
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (auto v : G[u])
        {
            if (--in[v] == 0)
            {
                S.push(v);
            }
        }
    }
    if (L.size() == n)
    {
        for (auto i : L)
            cout << i << ' ';
        return true;
    }
    else
    {
        return false;
    }
}

void debug()
{
    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        while (cin >> m && m)
        {
            G[i].push_back(m);
            in[m]++;
        }
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