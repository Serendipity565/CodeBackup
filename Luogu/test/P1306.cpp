#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const ll mod = 1e8;
const int ma = 2;

struct matrix
{
    ll a[5][5];
    matrix() { memset(a, 0, sizeof(a)); }   // 初始化
    matrix operator*(const matrix &t) const // 重载乘号为矩阵乘法
    {
        matrix ret;
        for (int i = 0; i < ma; ++i)
        {
            for (int j = 0; j < ma; ++j)
            {
                for (int k = 0; k < ma; ++k)
                {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * t.a[k][j]) % mod;
                }
            }
        }
        return ret;
    }
};

matrix fast(matrix x, ll k)
{
    matrix ret;
    for (int i = 0; i < ma; ++i)
    {
        ret.a[i][i] = 1; // 单位矩阵
    }
    while (k)
    {
        if (k & 1)
        {
            ret = ret * x;
        }
        x = x * x;
        k >>= 1;
    }
    return ret;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = __gcd(n, m);
    matrix T;
    T.a[0][0] = 1;
    T.a[0][1] = 1;
    T.a[1][0] = 1;
    T.a[1][1] = 2;
    ll k = (ans - 1) / 2;
    matrix result = fast(T, k);
    if (ans <= 2)
    {
        cout << 1 % mod << endl;
        return;
    }
    if (ans % 2 == 1)
    {
        cout << (result.a[0][0] + result.a[1][0]) % mod << endl;
    }
    else
    {
        cout << (result.a[0][1] + result.a[1][1]) % mod << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
