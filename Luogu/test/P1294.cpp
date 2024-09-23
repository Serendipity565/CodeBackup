#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<pair<int, int>> ve[22];
int t[22] = {0};
ll sum = 0;
ll mymax = 0;

void dfs(int a)
{
    for (auto x : ve[a])
    {
        if (t[x.first] == 0)
        {
            t[x.first] = 1;
            sum += x.second;
            if (sum > mymax)
            {
                mymax = sum;
                // cout << sum << endl;
            }
            dfs(x.first);
            sum -= x.second;
            t[x.first] = 0;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        ve[a].push_back({b, c});
        ve[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = 1;
        dfs(i);
        t[i] = 0;
    }
    cout << mymax << endl;
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