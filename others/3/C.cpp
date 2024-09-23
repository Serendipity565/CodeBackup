#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

struct C
{
    ll x;
    ll y;

} a[200005];

bool cmp(C a1, C a2)
{
    if (a1.x * (a2.y - 1) == a2.x * (a1.y - 1))
    {
        return (a1.x - 1) * a2.y < (a2.x - 1) * a1.y;
    }
    return a1.x * (a2.y - 1) < a2.x * (a1.y - 1);
}

int n;

void debug()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].x << " " << a[i].y << endl;
    }
    return;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans = 1;
    int now = 1;

    for (int i = now + 1; i <= n; i++)
    {
        if ((a[i].x - 1) * (a[now].y - 1) >= a[i].y * a[now].x && a[i].x != 1)
        {
            ans++;
            now = i;
        }
    }
    // debug();
    cout << ans << endl;
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