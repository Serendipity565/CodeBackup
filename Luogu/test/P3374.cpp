#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll n, m;
ll tr[500005] = {0};

void debug()
{

    return;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int k) // 单点修改
{
    while (x <= n)
    {
        tr[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x) // 整体前缀和
{
    ll tot = 0;
    while (x > 0)
    {
        tot += tr[x];
        x -= lowbit(x);
    }
    return tot;
}

int query(int l, int r) // 区间查询
{
    return getsum(r) - getsum(l - 1);
}

void solve()
{
    cin >> n >> m;
    int temp;

    // 建树状数组
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        update(i, temp);
    }

    // 接下来m次操作
    int op;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            update(x, y);
        }
        else
        {
            cout << query(x, y) << endl;
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