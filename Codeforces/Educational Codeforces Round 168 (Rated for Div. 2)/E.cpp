#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[200005] = {0};

void debug()
{
    return;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= i)
        {
            a[i] = -1;
        }
    }
    int j, x;
    for (int i = 1; i <= q; i++)
    {
        cin >> j >> x;
        if (a[j] == -1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "YES" << endl;
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