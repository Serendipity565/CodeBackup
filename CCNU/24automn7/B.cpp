#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void debug()
{
    return;
}

void solve()
{
    int n;
    int x, y;
    cin >> n >> x >> y;
    for (int diff = 1; diff <= (y - x); diff++)
    {
        if ((y - x) % diff == 0 && (y - x) / diff <= (n - 1))
        {
            int a = x;
            int cnt = n - ((y - x) / diff + 1);
            for (int i = 1; i <= cnt; i++)
            {
                if (a - diff >= 1)
                {
                    a -= diff;
                }
                else
                {
                    break;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                cout << (a + i * diff) << ' ';
            }
            cout << endl;
            return;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}