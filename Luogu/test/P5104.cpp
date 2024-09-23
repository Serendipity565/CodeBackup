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

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return ans;
}

void solve()
{
    ll w, n, k;
    cin >> w >> n >> k;
    ll m = fast_pow(2, k, mod);
    cout << (w * fast_pow(m, mod - 2, mod)) % mod << endl;
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