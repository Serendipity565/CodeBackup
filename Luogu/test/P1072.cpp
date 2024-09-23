#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}

void solve()
{
    ll a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    ll p = a0 / a1;
    ll q = b1 / b0;
    ll ans = 0;
    for (int x = 1; x * x <= b1; x++)
    {
        if (b1 % x == 0)
        {
            if (x % a1 == 0 && __gcd(x / a1, p) == 1 && __gcd(q, b1 / x) == 1)
            {
                ans++;
            }
            int y = b1 / x;
            if (x == y)
            {
                continue;
            }
            if (y % a1 == 0 && __gcd(y / a1, p) == 1 && __gcd(q, b1 / y) == 1)
            {
                ans++;
            }
        }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}