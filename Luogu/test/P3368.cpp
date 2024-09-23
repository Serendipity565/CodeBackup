#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll n;
ll a[500005] = {0};
ll tr[500005] = {0};

void debug()
{
    for (int i = 1; i <= n; i++)
    {
        cout << tr[i] << " ";
    }
    cout << endl;
    return;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int k) // 树状数组保存差分信息
{
    while (x <= n)
    {
        tr[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x) // 整体前缀和，差分和
{
    ll tot = 0;
    while (x > 0)
    {
        tot += tr[x];
        x -= lowbit(x);
    }
    return tot;
}

void solve()
{
    ll m;
    cin >> n >> m;
    ll temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int op;
    ll x, y;
    ll k;
    for (int i = 1; i <= m; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            update(x, k);
            update(y + 1, -k);
        }
        else
        {
            cin >> x;
            cout << getsum(x) + a[x] << endl;
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