#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void mul(ll a[4][4], ll b[4][4], ll res[4][4])
{
    ll temp[4][4] = {0};
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            temp[i][j] = 0;
            for (int k = 1; k <= 3; ++k)
            {
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            res[i][j] = temp[i][j];
        }
    }
}

void mypow(ll a[4][4], ll k, ll res[4][4])
{
    ll temp[4][4] = {0};
    for (int i = 1; i <= 3; ++i)
    {
        temp[i][i] = 1;
    }

    while (k)
    {
        if (k & 1)
        {
            mul(temp, a, temp);
        }
        mul(a, a, a);
        k >>= 1;
    }

    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            res[i][j] = temp[i][j];
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    if (n <= 3)
    {
        cout << 1 << endl;
        return;
    }

    ll a[4][4] = {{}, {0, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 1, 2}};
    ll ans[4][4] = {0};
    mypow(a, (n - 1) / 3, ans);
    ll sum = (ans[1][(n - 1) % 3 + 1] + ans[2][(n - 1) % 3 + 1] + ans[3][(n - 1) % 3 + 1]) % mod;
    cout << sum << endl;
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
