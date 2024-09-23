#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[1000006] = {0};
ll f[1000006] = {0};
void solve()
{
    ll p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0] = p;
    f[1] = p - q + a[1];
    for (int i = 2; i <= n + 1; i++)
    {
        f[i] = max(f[i - 1], f[i - 2]) - q + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] < q && f[i + 1] < q && (i + 1) <= n)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << f[n + 1] << endl;
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