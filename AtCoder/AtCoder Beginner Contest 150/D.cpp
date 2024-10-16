#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll a[100005] = {0};

void debug()
{
    return;
}

void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll lcm = a[1];
    for (int i = 2; i <= n; i++)
    {
        int g = __gcd(lcm, a[i]);
        lcm = lcm / g * a[i];
    }
    // cout << lcm << endl;
    if (lcm > 2 * m)
    {
        cout << 0 << endl;
        return;
    }
    cout << (2 * m + lcm) / (2 * lcm) << endl;
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