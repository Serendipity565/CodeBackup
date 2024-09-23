#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[200005] = {0};
ll b[200005] = {0};

void debug()
{

    return;
}

void solve()
{
    int n;
    cin >> n;
    ll mymin = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1 && a[i - 1] != 1)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            ll p = a[i - 1];
            ll now = a[i];
            ll extra = 0;
            while (p != 1 && p * p <= now)
            {
                extra -= 1, p *= p;
            }
            while (now < p)
            {
                extra++, now *= now;
            }

            b[i] = max(0ll, b[i - 1] + extra);
        }
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += b[i];
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