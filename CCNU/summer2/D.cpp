#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 2;
    a %= c;
    while (b)
    {
        ans = (ans * a) % c;

        a = (a * a) % c;
        b--;
    }
    return ans;
}

void solve()
{
    ll n, p;
    cin >> n >> p;
    cout << fast_pow(2, n, p);
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