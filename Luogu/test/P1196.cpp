#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[30004] = {0};
int f[30004] = {0};
int num[30004] = {0};
int n;

int find(int x)
{
    if (a[x] == x)
    {
        return a[x];
    }
    int fx = find(a[x]);
    f[x] += f[a[x]];
    return a[x] = fx;
}

void debug()
{

    return;
}

void solve()
{
    cin >> n;
    int x, y;
    char op;
    for (int i = 1; i <= 30000; i++)
    {
        a[i] = i;
        f[i] = 0;
        num[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> op >> x >> y;
        if (op == 'M')
        {
            int fx = find(x);
            int fy = find(y);
            f[fx] += num[fy];
            a[fx] = fy;
            num[fy] += num[fx];
            num[fx] = 0;
        }
        else if (op == 'C')
        {
            int fx = find(x);
            int fy = find(y);
            if (fx != fy)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << abs(f[x] - f[y]) - 1 << endl;
            }
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