#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, k;
ll a[1001][1001][2];
const ll Q = 1e9 + 7;

ll dfs(int now, int k, int d)
{
    if (k == 1)
    {
        return 1;
    }
    if (a[now][k][d] != -1)
    {
        return a[now][k][d];
    }

    ll ans = 2;
    if (d == 1)
    {
        if (now < n)
        {
            ans += dfs(now + 1, k, d) - 1;
        }
        ans %= Q;
        if (now > 1)
        {
            ans += dfs(now - 1, k - 1, 1 - d) - 1;
        }
        ans %= Q;
    }
    else
    {
        if (now > 1)
        {
            ans += dfs(now - 1, k, d) - 1;
        }
        ans %= Q;
        if (now < n)
        {
            ans += dfs(now + 1, k - 1, 1 - d) - 1;
        }
        ans %= Q;
    }
    a[now][k][d] = ans;
    return ans;
}

void solve()
{
    memset(a, -1, sizeof(a));
    cin >> n >> k;
    cout << dfs(1, k, 1) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
