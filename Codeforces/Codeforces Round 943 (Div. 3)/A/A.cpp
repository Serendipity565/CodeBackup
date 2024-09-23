#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int x;
    cin >> x;
    ll max_x = -1;
    int ans;
    for (int y = 1; y < x; y++)
    {
        ll now = __gcd(x, y) + y;
        if (now > max_x)
        {
            max_x = now;
            ans = y;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}