#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int id[100005] = {0};
int a[100005] = {0};
int b[100005] = {0};
int s[100005] = {0};
int len;

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
    return;
}

void add(int l, int r)
{
    int lid = id[l];
    int rid = id[r];
    if (lid == rid)
    {
        for (int i = l; i <= r; i++)
        {
            if (b[lid] == 0)
            {
                s[lid] = s[lid] - a[i] + ((a[i] + 1) % 2);
            }
            else
            {
                s[lid] = s[lid] + a[i] - ((a[i] + 1) % 2);
            }
            a[i] = (a[i] + 1) % 2;
        }
        return;
    }
    for (int i = l; id[i] == lid; i++)
    {
        if (b[lid] == 0)
        {
            s[lid] = s[lid] - a[i] + ((a[i] + 1) % 2);
        }
        else
        {
            s[lid] = s[lid] + a[i] - ((a[i] + 1) % 2);
        }
        a[i] = (a[i] + 1) % 2;
    }
    for (int i = lid + 1; i < rid; i++)
    {
        s[i] = len - s[i];
        b[i] = (b[i] + 1) % 2;
    }
    for (int i = r; id[i] == rid; i--)
    {
        if (b[rid] == 0)
        {
            s[rid] = s[rid] - a[i] + ((a[i] + 1) % 2);
        }
        else
        {
            s[rid] = s[rid] + a[i] - ((a[i] + 1) % 2);
        }
        a[i] = (a[i] + 1) % 2;
    }
}

int qur(int l, int r)
{
    int lid = id[l];
    int rid = id[r];
    int ans = 0;
    if (lid == rid)
    {
        for (int i = l; i <= r; i++)
        {
            ans += (a[i] + b[lid]) % 2;
        }
        return ans;
    }
    for (int i = l; id[i] == lid; i++)
    {
        ans += (a[i] + b[lid]) % 2;
    }
    for (int i = lid + 1; i < rid; i++)
    {
        ans += s[i];
    }
    for (int i = r; id[i] == rid; i--)
    {
        ans += (a[i] + b[rid]) % 2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        id[i] = (i - 1) / len + 1;
    }
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << id[i] << " ";
    // }
    for (int i = 1; i <= m; i++)
    {
        int op;
        int l, r;
        cin >> op >> l >> r;
        if (op == 0)
        {
            add(l, r);
            // debug();
        }
        else if (op == 1)
        {
            cout << qur(l, r) << endl;
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