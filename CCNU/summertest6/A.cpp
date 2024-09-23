#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, k;
ll a[1003][1003][2];
const ll Q = 1e9 + 7;

ll dfs(int now, int k, int d)
{
    if (now < 1 || now > n)
    {
        return 0;
    }
    if (k == 1)
    {
        return 0;
    }
    if (a[now][k][d] != -1)
    {
        return a[now][k][d];
    }
    ll result = 0;
    if (d == 1)
    {
        if (now >= 1 && now <= n)
        {
            result++;
            result += dfs(now + 1, k, d);
            result += dfs(now - 1, k - 1, 1 - d);
        }
    }
    else
    {
        if (now >= 1 && now <= n)
        {
            result++;
            result += dfs(now + 1, k - 1, 1 - d);
            result += dfs(now - 1, k, d);
        }
    }
    a[now][k][d] = result % Q;
    return a[now][k][d];
}

void solve()
{
    memset(a, -1, sizeof(a));
    cin >> n >> k;
    ll ans = dfs(1, k, 1);
    cout << (ans + 1) % Q << endl;
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
