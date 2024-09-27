#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll a[100005];

void debug()
{
    return;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    ll mymax = 0;
    for (int i = 0; i <= n; i++)
    {
        ll ans = a[n - i] - (n - i) * k;
        int cnt = 1;
        for (int j = n - i + 1; j <= n; j++)
        {
            ans += (a[j] - a[j - 1]) >> cnt;
            cnt++;
            if (cnt >= 32)
            {
                break;
            }
        }
        mymax = max(mymax, ans);
    }
    cout << mymax << endl;
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