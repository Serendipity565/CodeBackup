#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

char a[1003][1003];

int ans = 0;

void dfs(int i, int j, int n, int m, string s)
{
    if (i >= n || j >= m)
    {
        int cnt = 0;
        auto pos = s.find("gpt");
        while (pos != string::npos)
        {
            cnt++;
            pos = s.find("gpt", pos + 1);
        }
        ans = max(ans, cnt);
        return;
    }
    s += a[i][j];
    dfs(i + 1, j, n, m, s);
    dfs(i, j + 1, n, m, s);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, n, m, "");
    cout << ans << endl;
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
