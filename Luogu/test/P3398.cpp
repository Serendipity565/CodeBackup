#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, q;
vector<vector<int>> fa(100005, vector<int>(22));
vector<int> de(100005);
vector<int> v[100005];

void dfs(int root, int fath)
{
    fa[root][0] = fath;
    de[root] = de[fath] + 1;
    for (int i = 1; i <= 21; i++)
    {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    int sz = v[root].size();
    for (int i = 0; i < sz; ++i)
    {
        if (v[root][i] != fath)
        {
            dfs(v[root][i], root);
        }
    }
}

int lac(int x, int y)
{
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
            y = fa[y][j];
        }
        j++;
        temp /= 2;
    }
    if (x == y)
    {
        return y;
    }
    else
    {
        for (int j = 21; j >= 0; j--)
        {
            if (fa[x][j] != fa[y][j])
            {
                x = fa[x][j];
                y = fa[y][j];
            }
        }
    }
    return fa[x][0];
}

void debug()
{
    return;
}

void solve()
{
    cin >> n >> q;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    int a, b, c, d;
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b >> c >> d;
        int S = lac(a, b);
        int T = lac(c, d);
        if (de[S] < de[T])
        {
            swap(S, T);
            swap(a, c);
            swap(b, d);
        }
        if (lac(S, c) == S || lac(S, d) == S)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
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