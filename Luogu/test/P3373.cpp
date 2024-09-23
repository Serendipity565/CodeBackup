#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, m, p;
ll a[100005] = {0};

struct node
{
    long long v, mul, add;
} st[400007];
// 核心代码，维护lazytag
void pushdown(int root, int l, int r)
{
    int m = (l + r) / 2;
    // 儿子的值=此刻儿子的值*爸爸的乘法lazytag+儿子的区间长度*爸爸的加法lazytag
    st[root * 2].v = (st[root * 2].v * st[root].mul + st[root].add * (m - l + 1)) % p;
    st[root * 2 + 1].v = (st[root * 2 + 1].v * st[root].mul + st[root].add * (r - m)) % p;
    // 很好维护的lazytag
    st[root * 2].mul = (st[root * 2].mul * st[root].mul) % p;
    st[root * 2 + 1].mul = (st[root * 2 + 1].mul * st[root].mul) % p;
    st[root * 2].add = (st[root * 2].add * st[root].mul + st[root].add) % p;
    st[root * 2 + 1].add = (st[root * 2 + 1].add * st[root].mul + st[root].add) % p;
    // 把父节点的值初始化
    st[root].mul = 1;
    st[root].add = 0;
    return;
}
void build(int root, int l, int r)
{
    // 初始化lazytag
    st[root].mul = 1;
    st[root].add = 0;
    if (l == r)
    {
        st[root].v = a[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        st[root].v = st[root * 2].v + st[root * 2 + 1].v;
    }
    st[root].v %= p;
    return;
}
void updatemul(int root, int stdl, int stdr, int l, int r, ll k)
{
    if (r < stdl || stdr < l)
    {
        return;
    }
    if (l <= stdl && stdr <= r)
    {
        st[root].v = (st[root].v * k) % p;
        st[root].mul = (st[root].mul * k) % p;
        st[root].add = (st[root].add * k) % p;
        return;
    }
    // 假如给出的区间和本区间有交集，但是也有不交叉的部分
    // 先传递lazytag
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    updatemul(root * 2, stdl, m, l, r, k);
    updatemul(root * 2 + 1, m + 1, stdr, l, r, k);
    st[root].v = (st[root * 2].v + st[root * 2 + 1].v) % p;
    return;
}
void updatesum(int root, int stdl, int stdr, int l, int r, ll k)
{
    if (r < stdl || stdr < l)
    {
        return;
    }
    if (l <= stdl && stdr <= r)
    {
        st[root].add = (st[root].add + k) % p;
        st[root].v = (st[root].v + k * (stdr - stdl + 1)) % p;
        return;
    }
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    updatesum(root * 2, stdl, m, l, r, k);
    updatesum(root * 2 + 1, m + 1, stdr, l, r, k);
    st[root].v = (st[root * 2].v + st[root * 2 + 1].v) % p;
    return;
}
ll query(int root, int stdl, int stdr, int l, int r)
{
    if (r < stdl || stdr < l)
    {
        return 0;
    }
    if (l <= stdl && stdr <= r)
    {
        return st[root].v;
    }
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    return (query(root * 2, stdl, m, l, r) + query(root * 2 + 1, m + 1, stdr, l, r)) % p;
}
void solve()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    int op;
    int x, y, k;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            updatemul(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cin >> k;
            updatesum(1, 1, n, x, y, k);
        }
        else
        {
            cout << query(1, 1, n, x, y) << endl;
        }
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