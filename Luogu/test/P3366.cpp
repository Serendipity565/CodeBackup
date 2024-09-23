#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[5003] = {0};
struct P3366
{
    int x, y, z;
} b[200005];

bool cmp(P3366 a1, P3366 a2)
{
    return a1.z < a2.z;
}

void debug()
{

    return;
}

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

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y, z;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].x >> b[i].y >> b[i].z;
    }
    sort(b + 1, b + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fx = find(b[i].x);
        int fy = find(b[i].y);
        if (fx != fy)
        {
            a[fx] = fy;
            cnt += b[i].z;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            ans++;
        }
        if (ans > 1)
        {
            cout << "orz" << endl;
            return;
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