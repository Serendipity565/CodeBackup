#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int c[100005] = {0};
vector<int> ve[100005];
map<int, int> mp;
int num[100005] = {0};
int ans[100005] = {0};

void dfs(int now, int fa)
{
    int temp = mp[c[now]];
    for (auto x : ve[now])
    {
        if (x != fa)
        {
            mp[c[x]]++;
            num[x]++;
            dfs(x, now);
            num[now] += num[x];
        }
    }
    ans[now] = mp[c[now]] - temp;
}

void debug1()
{
    for (int i = 1; i <= n; i++)
    {
        cout << num[i] - ans[i] - 1 << " ";
    }
    cout << endl;
    return;
}

void debug2()
{
    for (int i = 1; i <= n; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    return;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    int u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, 0);
    num[1]++;
    debug2();
    debug1();
    for (int i = 1; i <= n; i++)
    {
        if (num[i] - ans[i] - 1 > num[i] / 2)
        {
            // cout << num[i] - ans[i] - 1 << " " << num[i] / 2 << endl;
            cout << i << " ";
        }
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
