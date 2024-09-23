#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll mod = 10007;

int ans[1005][1005] = {0};
int a, b, k, n, m;
void debug()
{
    return;
}

void c(int n, int m)
{
    for (int i = 0; i <= n; ++i)
    {
        ans[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            ans[i][j] = (ans[i - 1][j] + ans[i - 1][j - 1]) % mod;
        }
    }
    return;
}
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
    cin >> a >> b >> k >> n >> m;
    ans[0][0] = 1;
    c(k, n);
    cout << (ans[k][n] * fast_pow(a, n, mod) * fast_pow(b, m, mod)) % mod << endl;
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