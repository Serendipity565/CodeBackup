#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
int n, m, p, q;

int a[10004] = {0};

void debug()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}

int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    return a[x] = find(a[x]);
}

void solve()
{
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    int x;
    int y;
    for (int i = 1; i <= p; i++)
    {
        cin >> x >> y;
        int fx = find(x);
        int fy = find(y);
        if (fx < fy)
        {
            a[fy] = fx;
        }
        else if (fx > fy)
        {
            a[fx] = fy;
        }
    }
    int sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == 1)
        {
            sum1++;
        }
    }
    // debug();
    for (int i = 1; i <= m; i++)
    {
        a[i] = i;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        x = -x;
        y = -y;
        int fx = find(x);
        int fy = find(y);
        if (fx < fy)
        {
            a[fy] = fx;
        }
        else
        {
            a[fx] = fy;
        }
    }
    int sum2 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (find(i) == 1)
        {
            sum2++;
        }
    }
    // debug();
    cout << min(sum1, sum2) << endl;
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