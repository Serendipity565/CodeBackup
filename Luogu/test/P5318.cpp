#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<int> ve[100005];
int v[100005] = {0};
int f[100005] = {0};

void dfs(int k)
{
    for (auto x : ve[k])
    {
        if (v[x] == 0)
        {
            v[x] = 1;
            cout << x << " ";
            if (!ve[x].empty())
            {
                dfs(x);
            }
        }
    }
    return;
}

void bfs()
{
    queue<int> q;
    q.push(1);
    f[1] = 1;
    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp << " ";
        if (!ve[temp].empty())
        {
            for (auto x : ve[temp])
            {
                if (f[x] == 0)
                {
                    q.push(x);
                    f[x] = 1;
                }
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ve[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ve[i].empty())
        {
            sort(ve[i].begin(), ve[i].end());
        }
    }
    cout << 1 << " ";
    v[1] = 1;
    dfs(1);
    cout << endl;
    bfs();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}