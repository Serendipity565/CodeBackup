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

ll a[500005] = {0};
ll f[500005] = {0};

bool cmp(ll a, ll b)
{
    return a > b;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            f[i] = f[i - 1] + a[i];
        }
        else
        {
            f[i] = a[i];
        }
    }

    while (q--)
    {
        long long x;
        cin >> x;
        int l = 1, r = n, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (f[mid - 1] >= x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
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