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
    ll l, r;
    cin >> l >> r;
    ll cnt = 1;
    ll ans = 1;
    for (int i = l; i <= r;)
    {
        if (i + cnt <= r)
        {
            ans++;
            i = i + cnt;
            cnt++;
        }
        else
        {
            cout << ans << endl;
            return;
        }
    }
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