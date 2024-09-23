#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void debug()
{
    return;
}

int n = 2;

struct matrix
{
    ll a[5][5];
    matrix() { memset(a, 0, sizeof(a)); }   // 初始化
    matrix operator*(const matrix &t) const // 重载乘号为矩阵乘法
    {
        matrix ret;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
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
    for (int i = 0; i < n; ++i)
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
    ll q, p, a1, a2, y, m;
    cin >> q >> p >> a1 >> a2 >> y >> m;
    mod = m;
    matrix T;
    T.a[0][0] = p;
    T.a[0][1] = (p * q) % mod;
    T.a[1][0] = q;
    T.a[1][1] = (q * q + p) % mod;
    ll k = (y - 1) / 2;
    matrix result = fast(T, k);
    if (y <= 2)
    {
        if (y == 1)
        {
            cout << a1 % mod << endl;
        }
        else
        {
            cout << a2 % mod << endl;
        }
        return;
    }
    if (y % 2 == 1)
    {
        cout << (a1 * result.a[0][0] + a2 * result.a[1][0]) % mod << endl;
    }
    else
    {
        cout << (a1 * result.a[0][1] + a2 * result.a[1][1]) % mod << endl;
    }
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