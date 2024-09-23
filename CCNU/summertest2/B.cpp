#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    int a, x, y;
    cin >> a >> x >> y;
    if (y % a == 0)
    {
        cout << -1 << endl;
    }
    else if (y < a)
    {
        if ((2 * x) >= a || (2 * x) <= -a)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else if (y -= a; y % (2 * a) < a)
    {
        if ((2 * x) >= a || (2 * x) <= -a)
        {
            cout << -1 << endl;
        }
        else
        {
            int temp = y / (2 * a);
            cout << temp * 3 + 1 + 1 << endl;
        }
    }
    else
    {
        y -= a;
        if (x >= a || x <= -a || x == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int temp = y / (2 * a);
            if (x > 0)
            {
                cout << temp * 3 + 3 + 1 << endl;
            }
            else
            {
                cout << temp * 3 + 2 + 1 << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}