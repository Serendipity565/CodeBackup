#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[200005] = {0};
ll b[200005] = {0};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        cin >> b[j];
    }
    ll sum = 0;
    for (int i = n; i > m; i--)
    {
        sum += min(a[i], b[i]);
    }
    ll ans = sum + a[m];
    for (int i = m; i > 1; i--)
    {
        if (sum + a[i] < ans)
        {
            ans = sum + a[i];
        }
        sum += min(a[i], b[i]);
    }
    ans = min(ans, sum + a[1]);
    cout << ans << endl;
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