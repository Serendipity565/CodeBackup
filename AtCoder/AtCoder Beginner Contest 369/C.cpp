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

ll a[200005] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = n;
    ll k = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] - a[i - 1] != a[i + 1] - a[i])
        {
            ans += (i - k) * (i - k + 1) / 2;
            k = i;
        }
    }
    ans += (n - k) * (n - k + 1) / 2;
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