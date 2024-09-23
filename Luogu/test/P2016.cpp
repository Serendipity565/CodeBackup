#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int v[1505] = {0};
vector<int> p[1505];
int dp[1505][2] = {0};

void dfs(int x)
{
    dp[x][0] = 0;
    dp[x][1] = 1;
    for (int i = 0; i < p[x].size(); i++)
    {
        int y = p[x][i];
        if (v[y] == 0)
        {
            v[y] = 1;
            dfs(y);
            dp[x][0] += dp[y][1];
            dp[x][1] += min(dp[y][0], dp[y][1]);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int a;
    int head = 0;
    for (int i = 1; i < n; i++)
    {
        int m, k;
        cin >> m >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a;
            p[m].push_back(a);
            p[a].push_back(m);
        }
    }

    v[head] = 1;
    dfs(head);
    cout << min(dp[head][0], dp[head][1]) << endl;
    /*
    for (int i = 0; i <= 5; i++)
    {
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */
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