#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int a[105] = {0};
ll sum = 105;
int n;
unordered_map<string, ll> memo;

ll dfs(int i, int k)
{
    if (i == n + 1)
    {
        return 0;
    }

    string key = to_string(i) + "," + to_string(k);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    ll res = LLONG_MAX;
    if (a[i] == 0)
    {
        res = 1 + dfs(i + 1, 0);
    }
    if (a[i] == 1 && k != 2)
    {
        res = min(res, dfs(i + 1, 2));
    }
    else if (a[i] == 1 && k == 2)
    {
        res = min(res, 1 + dfs(i + 1, 0));
    }
    if (a[i] == 2 && k != 1)
    {
        res = min(res, dfs(i + 1, 1));
    }
    else if (a[i] == 2 && k == 1)
    {
        res = min(res, 1 + dfs(i + 1, 0));
    }
    if (a[i] == 3)
    {
        if (k == 1)
        {
            res = min(res, dfs(i + 1, 2));
        }
        else if (k == 2)
        {
            res = min(res, dfs(i + 1, 1));
        }
        else
        {
            res = min(res, min(dfs(i + 1, 1), dfs(i + 1, 2)));
        }
    }

    memo[key] = res;
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll result = dfs(1, 0);
    cout << result << endl;
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
