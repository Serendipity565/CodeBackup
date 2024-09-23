#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll a[110] = {0};
ll b[110][110] = {0};
const ll N = 1e6 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    b[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            for (ll k = 0; k <= min(j, a[i]); k++)
            {
                b[i][j] += b[i - 1][j - k];
                b[i][j] %= N;
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << b[n][m] << endl;
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