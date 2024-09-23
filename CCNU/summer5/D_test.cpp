#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(a) a.begin(), a.end()

#if LOCAL
#include "debug.h"
#else
#define debug(...) 114514
#endif

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    map<int, int> mp;
    vector<int> a(n + 1, 0), cnt(n + 1, 0), ans(n + 1, 0);
    function<void(int, int)> dfs = [&](int p, int fa)
    {
        mp[a[p]]++;
        cnt[p]++;
        int temp = mp[a[p]];
        for (auto x : tree[p])
        {
            if (x != fa)
            {
                dfs(x, p);
                cnt[p] += cnt[x];
            }
        }
        ans[p] = mp[a[p]] - temp;
    };
    int temp = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i != 1 && a[i] != a[1])
        {
            temp++;
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    cnt[1] = temp;
    // mp[a[1]]--;
    cnt[1]--;
    for (int i = 1; i <= n; i++)
        if (cnt[i] - ans[i] - 1 > cnt[i] / 2)
            cout << i << " ";
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}