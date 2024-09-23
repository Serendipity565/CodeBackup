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

struct C
{
    int m;
    int s;
} a[100005];

bool cmp(C c1, C c2)
{
    return c1.m < c2.m;
}

void solve()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].m >> a[i].s;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].m >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    ll ans = 0;
    ll sum = 0;
    int r = 1;
    for (int l = 1; l <= n; ++l)
    {
        while (r <= n && abs(a[l].m - a[r].m) < d)
        {
            ans += a[r].s;
            r++;
        }
        if (ans >= sum)
        {
            sum = ans;
        }
        ans -= a[l].s;
    }

    cout << sum << endl;
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