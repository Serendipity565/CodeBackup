#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;
typedef long double ld;

vector<bitset<25>> a(200005);
ll sum[25] = {0};

void solve()
{
    ll n;
    cin >> n;
    ll temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[i] = bitset<25>(temp);
    }

    for (int j = 24; j >= 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == 1)
            {
                sum[j]++;
            }
        }
    }
    // ll k = n * (n - 1) / 2;

    ll ans = 0;
    for (int i = 0; i <= 24; i++)
    {
        ans += (sum[i] * (sum[i] - 1) / 2 + (n - sum[i]) * sum[i]) * (1 << i);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}