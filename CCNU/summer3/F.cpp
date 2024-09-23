#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll q = 998244353;

int c[1005] = {0};

ll fast_pow(ll a, ll b, ll c)
{
    ll ans = 1;
    a %= c;
    while (b) // 不能写成b>1，否则会出问题！！！
    {
        if (b % 2 == 1) // 可以用b&1进行更快的判断
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b /= 2; // 可以用b>>=1来代替
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i] = (c[i - 1] * i) % q; // 阶乘
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll t = fast_pow((fast_pow(2, i, q) - 1), m - 1, q);
        t = (t * (c[n] / (c[i] * c[n - i]))) % q;
        ans = (ans + t) % q;
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