#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, m;
ll id[100005] = {0};
ll a[100005] = {0};
ll s[100005][4] = {0};
ll q = 998244353;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = (i - 1) / n + 1;
        s[id[i]][a[i]]++;
    }

    int x, y, c;
    int op;
    int f1, f2;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> op;
        if (op == 1)
        {
            cin >> f1 >> f2;
        }
        else if (op == 2)
        {
            cin >> f1 >> f2;
        }
        else
        {
            cin >> f1;
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