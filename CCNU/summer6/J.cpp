#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll n, m;
ll tr[1000006] = {0};

void debug()
{
    return;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int k)
{
    while (x <= n)
    {
        tr[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    ll tot = 0;
    while (x > 0)
    {
        tot += tr[x];
        x -= lowbit(x);
    }
    return tot;
}

int query(int l, int r)
{
    return getsum(r) - getsum(l - 1);
}

void solve()
{
    cin >> n >> m;
    int temp;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        update(i, max(0, temp));
    }

    int op;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            int k = query(x, x);
            update(x, -k);
            update(x, max(y, 0));
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