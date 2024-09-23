#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll ans[500005] = {0};
ll a[705][705] = {0};
void solve()
{
    ll n;
    cin >> n;
    ll mode;
    ll x, c;
    for (ll i = 1; i <= n; i++)
    {
        cin >> mode >> x >> c;
        if (mode == 1)
        {
            ans[x] += c;
            for (ll j = 1; j <= 704; j++)
            {
                a[j][x % j] += c;
            }
        }
        else
        {
            if (x <= 704)
            {
                cout << a[x][c] << endl;
            }
            else
            {
                ll res = 0;
                for (int i = c; i < 500004; i += x)
                {
                    res += ans[i];
                }
                cout << res << '\n';
            }
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}