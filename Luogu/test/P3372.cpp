#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, m;
int a[100005] = {0};

struct node
{
    long long v, add;
} st[400007];
// 核心代码，维护lazytag
void pushdown(int root, int l, int r)
{
    int m = (l + r) / 2;
    st[root * 2].v += st[root].add * (m - l + 1);
    st[root * 2 + 1].v += st[root].add * (r - m);
    st[root * 2].add += st[root].add;
    st[root * 2 + 1].add += st[root].add;
    // 把父节点的值初始化
    st[root].add = 0;
    return;
}
void build(int root, int l, int r)
{
    // 初始化lazytag
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
    return;
}

// 核心是找到最大能覆盖住l，r的子区间进行更改和标记
//  stdl，stdr为root管辖的区间
void updatesum(int root, int stdl, int stdr, int l, int r, ll k)
{
    if (r < stdl || stdr < l)
    {
        return;
    }
    // 如果能覆盖住，直接更新，子区间的以后在更改（懒标记）
    if (l <= stdl && stdr <= r)
    {
        st[root].add = st[root].add + k;
        st[root].v = st[root].v + k * (stdr - stdl + 1);
        return;
    }
    // 先下放以前的父节点的更新
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    updatesum(root * 2, stdl, m, l, r, k);
    updatesum(root * 2 + 1, m + 1, stdr, l, r, k);
    st[root].v = st[root * 2].v + st[root * 2 + 1].v;
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
    return query(root * 2, stdl, m, l, r) + query(root * 2 + 1, m + 1, stdr, l, r);
}
void debug()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << st[i].v << " ";
    }
    cout << endl;
    return;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    // debug();
    int op;
    int x, y, k;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            updatesum(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cout << query(1, 1, n, x, y) << endl;
            // debug();
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