#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int n, a[100005], b[100005], t1, t2;

void debug()
{
    return;
}

void solve()
{
    cin >> n;
    t1 = t2 = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0)
        {
            t2++;
            b[t2] = abs(y);
        }
        else
        {
            t1++;
            a[t1] = abs(x);
        }
    }
    sort(a + 1, a + 1 + t1);
    sort(b + 1, b + 1 + t2);
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
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