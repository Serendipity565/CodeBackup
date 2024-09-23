#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int a[100005] = {0};

void debug(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
        {
            k = i;
        }
    }
    double pre = 1;
    int r;
    double p;
    for (int i = 1; i <= m; i++)
    {
        cin >> r >> p;
        if (r >= k)
        {
            ans += p * pre;
            pre = (1 - p) * pre;
        }
    }
    if (k == 0)
    {
        cout << "1.000000" << endl;
        return;
    }
    cout << fixed << setprecision(6) << ans << endl;
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