#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, m;
vector<vector<int>> fa(100005, vector<int>(22));
vector<vector<int>> sum(100005, vector<int>(22));
vector<int> de(100005);
vector<int> v[100005];

void dfs(int root, int fath)
{
    fa[root][0] = fath;
    de[root] = de[fath] + 1;
    sum[root][0] = v[root].size();
    for (int i = 1; i <= 21; i++)
    {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
        sum[root][i] = sum[fa[root][i - 1]][i - 1] + sum[root][i - 1];
    }
    for (auto x : v[root])
    {
        if (x != fath)
        {
            dfs(x, root);
        }
    }
}

int lac(int x, int y)
{
    if (x == y)
    {
        return v[x].size();
    }
    if (de[x] > de[y])
    {
        swap(x, y);
    }
    int temp = de[y] - de[x];
    int ans = 0;
    int j = 0;
    while (temp)
    {
        if (temp % 2 == 1)
        {
            ans += sum[y][j];
            y = fa[y][j];
        }
        j++;
        temp /= 2;
    }
    if (x == y)
    {
        return ans + v[y].size();
    }
    else
    {
        for (int j = 21; j >= 0; j--)
        {
            if (fa[x][j] != fa[y][j])
            {
                ans += sum[x][j] + sum[y][j];
                x = fa[x][j];
                y = fa[y][j];
            }
        }
    }
    ans += sum[x][0] + sum[y][0] + sum[fa[x][0]][0];
    return ans;
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        cout << lac(u, v) << endl;
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