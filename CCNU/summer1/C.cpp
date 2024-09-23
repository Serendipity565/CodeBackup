#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll a[200005] = {0};
ll b[200005] = {0};
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] + b[i - 1];
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += a[i] * i;
    }
    ans = sum;
    // cout << ans << endl;
    for (int i = m + 1; i <= n; i++)
    {
        sum += a[i] * m - (b[i - m] - b[i - m - 1]) - (b[i - 1] - b[i - m]);
        if (sum > ans)
        {
            ans = sum;
            // cout << ans << endl;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}