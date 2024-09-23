#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n, m, w;
struct P1455
{
    int c;
    int d;
} b[10004];
int f[10004] = {0};
int a[10001] = {0};

int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    else
    {
        return a[x] = find(a[x]);
    }
}

void solve()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].c >> b[i].d;
        a[i] = i;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int fx = find(x);
        int fy = find(y);
        a[fx] = fy;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            b[find(i)].d += b[i].d;
            b[i].d = 0;
            b[find(i)].c += b[i].c;
            b[i].c = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i].c > 0)
        {
            for (int j = w; j >= b[i].c; j--)
            {
                f[j] = max(f[j], f[j - b[i].c] + b[i].d);
            }
        }
    }
    cout << f[w] << endl;
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