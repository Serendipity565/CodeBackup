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
    ll mymin = 1e10;
    ll mymax = 0;
    ll l;
    ll r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        mymax = max(mymax, l);
        mymin = min(mymin, r);
    }
    cout << max(0ll, mymax - mymin) << endl;
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