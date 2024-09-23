#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    ld ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(1.0L, ans) / 6.0 + max(2.0L, ans) / 6.0 + max(3.0L, ans) / 6.0 + max(4.0L, ans) / 6.0 + max(5.0L, ans) / 6.0 + max(6.0L, ans) / 6.0;
    }
    cout << fixed << setprecision(10) << ans << endl;
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