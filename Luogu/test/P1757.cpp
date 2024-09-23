#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll dp[1003] = {0};
ll w[1003] = {0};
ll v[1003] = {0};
vector<int> c[105];

void solve()
{
    int m, n;
    cin >> m >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> x;
        c[x].push_back(i);
    }
    for (auto a : c) // 组别
    {
        for (int j = m; j > 0; j--)
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (j >= w[a[i]])
                {
                    dp[j] = max(dp[j], dp[j - w[a[i]]] + v[a[i]]);
                }
            }
        }
    }

    cout << dp[m] << endl;
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