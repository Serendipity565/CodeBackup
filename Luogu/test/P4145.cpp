#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll len;
ll id[100005] = {0};
ll s[100005] = {0};
ll a[100005] = {0};
ll b[100005] = {0}; // 统计当前区块有多少不为1的

void debug()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 4; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 4; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void add(ll l, ll r)
{
    ll lid = id[l], rid = id[r];
    if (lid == rid)
    {
        if (b[lid] != 0)
        {
            for (int i = l; i <= r; i++)
            {
                if (a[i] != 1)
                {
                    s[lid] -= a[i];
                    a[i] = sqrt(a[i]);
                    if (a[i] == 1)
                    {
                        b[lid]--;
                    }
                    s[lid] += a[i];
                }
            }
        }
        return;
    }
    if (b[lid] != 0)
    {
        for (int i = l; id[i] == lid; i++)
        {
            if (a[i] != 1)
            {
                s[lid] -= a[i];
                a[i] = sqrt(a[i]);
                if (a[i] == 1)
                {
                    b[lid]--;
                }
                s[lid] += a[i];
            }
        }
    }
    for (int j = lid + 1; j < rid; j++)
    {
        if (b[j] != 0)
        {
            for (int i = (j - 1) * len + 1; i <= j * len; i++)
            {
                if (a[i] != 1)
                {
                    s[j] -= a[i];
                    a[i] = sqrt(a[i]);
                    if (a[i] == 1)
                    {
                        b[j]--;
                    }
                    s[j] += a[i];
                }
            }
        }
    }
    if (b[rid] != 0)
    {
        for (int i = r; id[i] == rid; i--)
        {
            if (a[i] != 1)
            {
                s[rid] -= a[i];
                a[i] = sqrt(a[i]);
                if (a[i] == 1)
                {
                    b[rid]--;
                }
                s[rid] += a[i];
            }
        }
    }
    return;
}

ll query(ll l, ll r)
{
    ll lid = id[l], rid = id[r];
    ll ans = 0;
    if (lid == rid)
    {
        for (int i = l; i <= r; i++)
        {
            ans += a[i];
        }
        return ans;
    }
    for (int i = l; id[i] == lid; i++)
    {
        ans += a[i];
    }
    for (int i = lid + 1; i < rid; i++)
    {
        ans = ans + s[i];
    }
    for (int i = r; id[i] == rid; i--)
    {
        ans += a[i];
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = (i - 1) / len + 1;
        s[id[i]] += a[i];
        if (a[i] != 1)
        {
            b[id[i]]++;
        }
    }
    // debug();
    cin >> m;
    int op;
    ll l, r, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> r >> l;
        if (l > r)
        {
            swap(l, r);
        }
        if (op == 0)
        {
            add(l, r);
            // debug();
        }
        else if (op == 1)
        {
            cout << query(l, r) << endl;
        }
    }
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