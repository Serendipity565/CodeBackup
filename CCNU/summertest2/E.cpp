#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[100005] = {0};
ll b[100005] = {0};

void solve()
{
    ll mymin = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        auto lb = lower_bound(b + 1, b + 1 + m, a[i]);

        ll l = (lb == b + 1 + m) ? INT64_MAX : *(lb);
        ll r = (lb == b + 1) ? *(lb) : *(lb - 1);
        // cout << l << " " << r << endl;
        ll temp = min(llabs(l - a[i]), llabs(r - a[i]));
        mymin = max(temp, mymin);
    }
    cout << mymin << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}