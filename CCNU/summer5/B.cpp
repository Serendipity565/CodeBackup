#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll a[1000006] = {0};
ll n;

ll myfind(ll x)
{
    ll l = 0;
    ll r = n;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (a[mid] <= x)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    int q;
    cin >> q;
    ll x;
    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        cout << myfind(x) << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
