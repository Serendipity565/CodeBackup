#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int m;
int a[2003] = {0};

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

void debug()
{

    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        a[i] = i;
    }
    cin >> m;
    int x, y;
    char op;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 'F')
        {
            int fx = find(x);
            int fy = find(y);
            a[fx] = fy;
        }
        else if (op == 'E')
        {
            a[find(x + n)] = find(y);
            a[find(y + n)] = find(x);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
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