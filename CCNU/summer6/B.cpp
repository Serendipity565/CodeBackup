#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int n, m;
ll a[100005] = {0};

struct node
{
    long long v, maxv, add;
} st[400007];

void pushdown(int root, int l, int r)
{
    int m = (l + r) / 2;
    st[root * 2].v = (st[root].add * (m - l + 1));
    st[root * 2 + 1].v = (st[root].add * (r - m));
    st[root * 2].maxv = st[root].add + st[root * 2].maxv;
    st[root * 2 + 1].maxv = st[root].add + st[root * 2 + 1].maxv;
    st[root * 2].add += st[root].add;
    st[root * 2 + 1].add += st[root].add;
    st[root].add = 0;
}

void build(int root, int l, int r)
{
    if (l == r)
    {
        st[root].v = a[l];
        st[root].maxv = a[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        st[root].v = st[root * 2].v + st[root * 2 + 1].v;
        st[root].maxv = max(st[root * 2].maxv, st[root * 2 + 1].maxv);
    }
}

void updatemul(int root, int stdl, int stdr, int l, int r, ll k)
{
    if (r < stdl || stdr < l)
    {
        return;
    }
    if (l <= stdl && stdr <= r)
    {
        st[root].v = (st[root].v * k);
        st[root].maxv = (st[root].maxv * k);
        st[root].add = (st[root].add * k);
        return;
    }
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    updatemul(root * 2, stdl, m, l, r, k);
    updatemul(root * 2 + 1, m + 1, stdr, l, r, k);
    st[root].v = (st[root * 2].v + st[root * 2 + 1].v);
    st[root].maxv = max(st[root * 2].maxv, st[root * 2 + 1].maxv);
}

void updatesum(int root, int stdl, int stdr, int l, int r, ll k)
{
    if (r < stdl || stdr < l)
    {
        return;
    }
    if (l <= stdl && stdr <= r)
    {
        st[root].add += k;
        st[root].v += k * (stdr - stdl + 1);
        st[root].maxv += k;
        return;
    }
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    updatesum(root * 2, stdl, m, l, r, k);
    updatesum(root * 2 + 1, m + 1, stdr, l, r, k);
    st[root].v = (st[root * 2].v + st[root * 2 + 1].v);
    st[root].maxv = max(st[root * 2].maxv, st[root * 2 + 1].maxv);
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
    return (query(root * 2, stdl, m, l, r) + query(root * 2 + 1, m + 1, stdr, l, r));
}

ll querymax(int root, int stdl, int stdr, int l, int r)
{
    if (r < stdl || stdr < l)
    {
        return LLONG_MIN;
    }
    if (l <= stdl && stdr <= r)
    {
        return st[root].maxv;
    }
    pushdown(root, stdl, stdr);
    int m = (stdl + stdr) / 2;
    return max(querymax(root * 2, stdl, m, l, r), querymax(root * 2 + 1, m + 1, stdr, l, r));
}

void solve()
{
    cin >> n >> m;
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
            ll k = query(1, 1, n, x, x);
            updatesum(1, 1, n, x, x, -k);
            updatesum(1, 1, n, x, x, y);
        }
        else if (op == 2)
        {
            ll mysum = query(1, 1, n, x, y);
            ll mymax = querymax(1, 1, n, x, y);
            if (mysum - mymax > mymax)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
