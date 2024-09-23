#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, m;
ll a[305][305] = {0};
ll tr[305][305][105] = {0};

void debug()
{
    return;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int y, int c, int k)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        for (int j = y; j <= m; j += lowbit(j))
        {
            tr[i][j][c] += k;
        }
    }
}

int getsum(int x, int y, int c)
{
    int tot = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            tot += tr[i][j][c];
        }
    }
    return tot;
}

int query(int x0, int y0, int x2, int y2, int c)
{
    return getsum(x2, y2, c) - getsum(x0 - 1, y2, c) - getsum(x2, y0 - 1, c) + getsum(x0 - 1, y0 - 1, c);
}

void solve()
{
    cin >> n >> m;

    // 建树状数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            update(i, j, a[i][j], 1);
        }
    }

    int q;
    cin >> q;
    int x, y, c;
    int op;
    for (int i = 1; i <= q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> c;
            update(x, y, a[x][y], -1);
            a[x][y] = c;
            update(x, y, c, 1);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> x2 >> y1 >> y2 >> c;
            cout << query(x1, y1, x2, y2, c) << endl;
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