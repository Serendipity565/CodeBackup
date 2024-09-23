#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int n;
int k;
int a[150004] = {0};

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
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++)
    {
        a[i] = i;
    }
    int cnt = 0;
    int op;
    int x, y;
    for (int i = 1; i <= k; i++)
    {
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            cnt++;
        }
        else if (op == 1)
        {
            if (find(x + n) == find(y) || find(x) == find(y + n))
            {
                cnt++;
            }
            else
            {
                a[find(x)] = find(y);
                a[find(x + n)] = find(y + n);
                a[find(x + 2 * n)] = find(y + 2 * n);
            }
        }
        else if (op == 2)
        {
            if (find(x) == find(y) || find(x) == find(y + n))
            {
                cnt++;
            }
            else
            {
                a[find(x)] = find(y + 2 * n);
                a[find(x + n)] = find(y);
                a[find(x + 2 * n)] = find(y + n);
            }
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