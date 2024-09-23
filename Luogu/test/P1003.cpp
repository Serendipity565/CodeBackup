#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[10005] = {0};
int b[10005] = {0};
int c[10005] = {0};
int d[10005] = {0};
void debug()
{
    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int x, y;
    int ans = -1;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        if ((x >= a[i] && x <= a[i] + c[i]) && (y >= b[i] && y <= b[i] + d[i]))
        {
            ans = i;
        }
    }
    cout << ans;
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