#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int r[6005] = {0};
int v[6005] = {0};
vector<int> p[6005];
int dp[6005][2] = {0};

void dfs(int x)
{
    dp[x][0] = 0;
    dp[x][1] = r[x];
    for (int i = 0; i < p[x].size(); i++)
    {
        int y = p[x][i];
        dfs(y);
        dp[x][0] += max(dp[y][0], dp[y][1]);
        dp[x][1] += dp[y][0];
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        p[b].push_back(a);
        v[a] = 1;
    }
    int head;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            head = i;
            break;
        }
    }
    dfs(head);
    cout << max(dp[head][0], dp[head][1]) << endl;
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