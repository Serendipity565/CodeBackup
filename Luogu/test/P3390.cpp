#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void debug()
{
    return;
}
const ll mod = 1e9 + 7;
int n;
ll k;

void mul(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &res, int n)
{
    vector<vector<ll>> temp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[i][j] = temp[i][j];
        }
    }
}

void mypow(vector<vector<ll>> &a, ll k, vector<vector<ll>> &res, int n)
{
    vector<vector<ll>> temp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        temp[i][i] = 1;
    }

    while (k)
    {
        if (k & 1)
        {
            mul(temp, a, temp, n);
        }
        mul(a, a, a, n);
        k >>= 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[i][j] = temp[i][j];
        }
    }
}

struct matrix
{
    ll a[110][110];
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
    cin >> n >> k;

    matrix T;
    // 初始化矩阵 T
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> T.a[i][j];
        }
    }

    matrix result = fast(T, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result.a[i][j] << " ";
        }
        cout << endl;
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
