#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    ll type, n, m, p;
    cin >> type >> n >> m >> p;
    mod = p;
    n = n - m + 1;
    ll ans = 1;
    for (int i = n - m + 1; i <= n; ++i)
    {
        ans = ans * i % mod;
    }
    cout << ans << endl;
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