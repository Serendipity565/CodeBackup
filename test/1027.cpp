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

ll my_gcd(ll a, ll b)
{
    while (a % b != 0)
    {
        ll c = a;
        a = b;
        b = c % b;
    }
    return b;
}

void solve()
{
    ll a, b, n;
    cin >> a >> b >> n;
    ll c = my_gcd(a, b);
    ll lcm = a * b / c;
    ll count = (n / lcm) * min(a, b);

    for (ll i = n / lcm * lcm + 1; i <= n; i++)
    {
        if ((i - 1) % a + 1 == (i - 1) % b + 1)
        {
            count++;
        }
    }
    cout << count << endl;

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