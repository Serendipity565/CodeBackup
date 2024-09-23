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
    ll a, b;
    cin >> b >> a;
    ll ans = 0;
    if (a == b)
    {
        ans--;
    }
    a *= b;
    for (long long i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0 && __gcd(i, a / i) == b)
        {
            ans += 2;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}