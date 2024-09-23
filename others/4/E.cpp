#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

ll a[105] = {0};

void debug(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << a[1] << endl;
        return;
    }

    int sum = a[n];
    int r = n;
    for (int i = n; i > 1; i--)
    {
        if (a[i] >= a[i - 1])
        {
            sum += a[i - 1];
            int p = sum % (r - i + 2);
            for (int j = i - 1; j <= r; j++)
            {
                a[j] = sum / (r - i + 2) + (p > 0 ? 1 : 0);
                p--;
            }
        }
        else
        {
            r = i - 1;
            sum = a[i - 1];
        }
    }
    debug(n);
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * a[i]) % mod;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
