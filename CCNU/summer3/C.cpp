#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[45][45] = {0};
ll dp[45][45] = {0};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][2 * n - j] = a[i][j];
        }
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            a[i][j] += a[i][j - 1];
        }
    }
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