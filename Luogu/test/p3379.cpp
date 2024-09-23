#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<vector<int>> fa(500005, vector<int>(35));
vector<int> de(500005);
// int lg[500005] = {0};
vector<int> v[500005];

/*
void pre()
{
    lg[1] = 0;
    lg[2] = 1;
    for (int i = 3; i <= 100004; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    return;
}
*/

void dfs(int root, int fath)
{
    fa[root][0] = fath;
    de[root] = de[fath] + 1;
    for (int i = 1; i <= 34; i++)
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
        for (int j = 34; j >= 0; j--)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, s;
    int a, b;
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(s, 0);
    /*
    for (int i = 1; i <= 5; i++)
    {
        cout << fa[i][0] << endl;
    }
    */
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        cout << lac(a, b) << endl;
    }
    return 0;
}